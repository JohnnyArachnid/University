import itertools

import numpy as np
import random

from loss_functions import loss_function1
from visualization import visualize


class Container:
    '''
    It is a base container of the building, it is 3m x 3m.

    it **ONLY** has 5 type 'K', 'S', 'C', 'H', '0':
        * K - kitchen
        * S - sanitary
        * C - halls (aka common)
        * H - house
        * 0 - empty space

    All the types except 'empty space' has doors that points to a different empty space. If you will provide doors to the empty space ``ValueError`` will be raised.
    '''
    def __init__(self, id:int,type:str, door = None):
        self.type = type
        self.id = id

        if type == '0' and door is not None:
            raise ValueError(f'Empty space cannot have doors: {door}')
        self.door = door

    def __str__(self):
        return self.__repr__()

    def __repr__(self):
        '''
        Representation looks like this i show at bottom, except ``'0'`` which doesnt have door
        :return: type/id>door
        '''
        if self.type != '0':
            return f"{self.type}/{self.id}>{'_' if self.door is None else self.door}"
        else:
            return f"{self.type}/{self.id}"

    # def __eq__(self, other):
    #     if type(other) == int:
    #         return self.id == other
    #     elif type(other) == Container:
    #         return self.id == other.id

    @property
    def door(self):
        return self._door

    @door.setter
    def door(self, d):
        # only need for initialization should be used during working program
        if d is None:
            self._door = None
            return

        if d._type != '0':
            raise ValueError(f'Doors cannot lead to nothing except empty space: \n{self} tried assign with door {d}')
        if self._type == '0':
            raise ValueError(f'Empty space cannot have doors: \n{self} tried assign with door {d}')
        self._door = d

    @property
    def type(self):
        return self._type

    @type.setter
    def type(self,t):
        types = ['K', 'S', 'C', 'H', '0']
        if t not in types:
            raise ValueError('Type must be either K or S or C or H or 0')
        else:
            self._type = t

class House:
    '''
    This class represents a 'house' which contains all the Containers of different type. The space is rectangular shape with x width and y height. One cell in matrix represent one container of each type.

    The output of standard __init__ is maze like shape matrix with, all Containers if possible having doors to nearest random neighbor.

    The class have specific kind of attributes:
        * **x**: `width of whole house`
        * **y**: `height of whole house`
        * **houses**: `number of houses containers`
        * **sanitaries**: `number of sanitary containers`
        * **kitchen**: `number of kitchen containers`
        * **halls**: `number of halls containers`
        * **matrix**: `containing matrix with containers`
        * **entrance**: `coordinates of entrance`
    '''
    def __init__(self, x:int ,y:int, matrix=None):
        if x*y < 6:
            raise ValueError('No space for any of the containers')

        self.x = x
        self.y = y
        if matrix is not None:
            if type(matrix) != np.ndarray:
                matrix = np.array(matrix,dtype=Container)
            self.x = matrix.shape[1]
            self.y = matrix.shape[0]
        self.houses = 0
        self.kitchens = 0
        self.sanitaries = 0
        self.halls = 0
        self.ent = None
        if matrix is None:
            self.matrix = self.__generate_maze()
        else:
            self.matrix = self.__generate_existing(matrix)

        self.__count()

    def __repr__(self):
        # Find the maximum width of each column
        num_columns = max(len(row) for row in self.matrix)
        column_widths = [0] * num_columns

        for row in self.matrix:
            for col_idx, item in enumerate(row):
                column_widths[col_idx] = max(column_widths[col_idx], len(str(item)))

        # Format each row to align items in columns
        formatted_rows = []
        for row in self.matrix:
            formatted_row = []
            for col_idx in range(num_columns):
                if col_idx < len(row):
                    item = str(row[col_idx]).center(column_widths[col_idx])
                else:
                    item = " " * column_widths[col_idx]  # Add empty padding for missing values
                formatted_row.append(item)
            formatted_rows.append("| " + " | ".join(formatted_row) + " |")

        # Add horizontal separators and ceiling/floor
        row_separator = "-" * len(formatted_rows[0])
        result = (
                row_separator + "\n" +  # Ceiling
                f"\n{row_separator}\n".join(formatted_rows) + "\n" +  # Rows with separators
                row_separator  # Floor
        )

        return result

    def __str__(self):
        return self.__repr__()

    def __getitem__(self, index:int) -> np.array:
        '''
        :param index: number of index looking for
        :return: matrix with representation of containers
        '''
        if type(index) != int:
            raise TypeError("Bad type")
        else:
            return self.matrix[index]

    def __len__(self):
        return self.x*self.y


    def __count(self):
        self.houses = 0
        self.sanitaries = 0
        self.halls = 0
        self.kitchens = 0
        for row in self.matrix:
            for cont in row:
                if cont.type == 'H':
                    self.houses += 1
                elif cont.type == 'S':
                    self.sanitaries += 1
                elif cont.type == 'K':
                    self.kitchens += 1
                elif cont.type == 'C':
                    self.halls += 1

    def __generate_maze(self):
        # Ensure rows and cols are odd for proper maze generation
        rows = self.y
        cols = self.x
        rows = rows if rows % 2 == 1 else rows + 1
        cols = cols if cols % 2 == 1 else cols + 1

        # Create a grid filled with walls
        maze = np.ones((rows, cols), dtype=Container)

        # Starting point
        start_row, start_col = 1, 1
        maze[start_row][start_col] = 0
        maze[start_row][start_col - 1] = -1
        self.ent = (start_row, start_col-1)
        # Directions (up, down, left, right)
        directions = [(0, 2), (0, -2), (2, 0), (-2, 0)]

        # Stack for backtracking
        stack = [(start_row, start_col)]

        while stack:
            current_row, current_col = stack[-1]
            random.shuffle(directions)
            carved = False

            for dr, dc in directions:
                new_row, new_col = current_row + dr, current_col + dc
                between_row, between_col = current_row + dr // 2, current_col + dc // 2

                # Check bounds and if the cell is unvisited
                if 1 <= new_row < rows and 1 <= new_col < cols and maze[new_row][new_col] == 1:
                    maze[new_row][new_col] = 0
                    maze[between_row][between_col] = 0
                    stack.append((new_row, new_col))
                    carved = True
                    break

            if not carved:
                stack.pop()
        # change 0 and 1 to a specific cell
        arr = ['K', 'S', 'C', 'H', 'H', 'H']
        np.random.shuffle(arr)
        iter_type = itertools.cycle(arr)
        id = 0
        for x, list in enumerate(maze):
            for y, _ in enumerate(list):
                if maze[x][y] == -1:
                    maze[x][y] = Container(-1, '0')
                    id -= 1
                elif maze[x][y] == 1:
                    maze[x][y] = Container(id, next(iter_type))
                elif maze[x][y] == 0:
                    maze[x][y] = Container(id, '0')
                id += 1
        for x, list in enumerate(maze):
            for y, cont in enumerate(list):
                if cont.type != '0':
                    try:
                        if maze[x-1][y].type == '0':
                            cont.door = maze[x-1][y]
                    except IndexError: pass
                    try:
                        if maze[x+1][y].type == '0':
                            cont.door = maze[x+1][y]
                    except IndexError: pass
                    try:
                        if maze[x][y+1].type == '0':
                            cont.door = maze[x][y+1]
                    except IndexError: pass
                    try:
                        if maze[x][y-1].type == '0':
                            cont.door = maze[x][y-1]
                    except IndexError: pass
        return maze

    def __generate_existing(self,maze):
        # change 0 and 1 to a specific cell
        arr = ['K', 'S', 'C', 'H', 'H', 'H']
        np.random.shuffle(arr)
        iter_type = itertools.cycle(arr)
        id = 0
        for x, list in enumerate(maze):
            for y, _ in enumerate(list):
                if maze[x][y] == -1:
                    maze[x][y] = Container(-1, '0')
                    id -= 1
                elif maze[x][y] == 1:
                    maze[x][y] = Container(id, next(iter_type))
                elif maze[x][y] == 0:
                    maze[x][y] = Container(id, '0')
                id += 1
        for x, list in enumerate(maze):
            for y, cont in enumerate(list):
                if cont.type != '0':
                    try:
                        if maze[x - 1][y].type == '0':
                            cont.door = maze[x - 1][y]
                    except IndexError:
                        pass
                    try:
                        if maze[x + 1][y].type == '0':
                            cont.door = maze[x + 1][y]
                    except IndexError:
                        pass
                    try:
                        if maze[x][y + 1].type == '0':
                            cont.door = maze[x][y + 1]
                    except IndexError:
                        pass
                    try:
                        if maze[x][y - 1].type == '0':
                            cont.door = maze[x][y - 1]
                    except IndexError:
                        pass
        return maze


    def count_block(self):
        '''
        Updates count of blocks that are inside the matrix and returns dictionary with it
        :return: ``dict`` of counted containers
        '''
        self.__count()
        return {
            'H': self.houses,
            'S': self.sanitaries,
            'K': self.kitchens,
            'C': self.halls,
            '0': len(self) - (self.halls + self.kitchens + self.sanitaries + self.houses)
        }

    def validate_doors(self):
        '''
        This function checks if doors at are the correct places so they neighbor a specific cell
        :return: None
        '''
        maze = self.matrix
        for x, list in enumerate(maze):
            for y, cont in enumerate(list):
                if cont.type != '0' :

                    # if doesnt have doors add them if cannot add stay at None
                    if cont.door is None:
                        for dx, dy in [(-1, 0), (1, 0), (0, 1), (0, -1)]:
                            try:
                                if maze[x + dx][y + dy].type == '0':
                                    cont.door = maze[x + dx][y + dy]
                            except IndexError: pass
                    # if have doors but they are smth different than '0' find nearest doors or None
                    elif cont.door.type != '0':
                        flag = True
                        for dx, dy in [(-1, 0), (1, 0), (0, 1), (0, -1)]:
                            try:
                                if maze[x + dx][y + dy].type == '0':
                                    cont.door = maze[x + dx][y + dy]
                                    flag = False
                            except IndexError: pass
                        if flag:
                            cont.door = None



    def check_connectivity_subgraphs(self, flag=False):
        '''
       Checks number of sub graphs in the 'house' and number of connected to pathways containers
       :return: Count of all subgraphs and count of unavaible segments
       '''

        visited = np.zeros((self.matrix.shape[1],self.matrix.shape[0]))
        stack = []

        subgraphs_count = 0
        subgraphs = set([])

        for x,list in enumerate(self.matrix):
            for y,cont in enumerate(list):
                if cont.type == '0':
                    subgraphs.add((x,y))

        while subgraphs:
            x_s, y_s = subgraphs.pop()
            subgraphs_count += 1
            stack.append((x_s,y_s))
            visited[x_s][y_s] = 1
            while stack:
                #print(f"Stack: {stack}\nVis: \n{visited}\nSubgraphs: {subgraphs}")
                x,y = stack.pop()
                for dx, dy in [(-1, 0), (1, 0), (0, 1), (0, -1)]:
                    try:
                        if (x + dx)<0 or (y + dy)<0:
                            continue
                        if self.matrix[x + dx][y + dy].type == '0':
                            if visited[x + dx][y + dy] == 0:
                                #print(x + dx, y + dy, self.matrix[x + dx][y + dy])
                                stack.append((x + dx,y + dy))
                                visited[x + dx][y + dy] = 1
                                subgraphs.remove((x + dx,y + dy))
                        else:
                            if visited[x + dx][y + dy] == 0:
                                visited[x + dx][y + dy] = 1
                    except (IndexError, KeyError):
                        pass
        if subgraphs_count == 0:
            subgraphs_count = self.x*self.y
        if flag:
            print(visited)
        all = self.matrix.shape[0]*self.matrix.shape[1]
        return subgraphs_count, all - np.sum(visited)

    def get_distance(self):
        '''
        Fucntion that calculate distance between every house and its nearest neighbor container with utilities
        :return: (id_house,[kitchen, sanitary, common])
        '''
        h_list = []
        shortest_paths = []

        # adding empty space that doors open to array
        for x,list in enumerate(self.matrix):
            for y,cont in enumerate(list):
                if cont.type == 'H':
                    for x_v,y_v in [(0,1),(0,-1),(1,0),(-1,0)]:
                        if (x + x_v)<0 or (y + y_v)<0:
                            continue
                        try:
                            if cont.door is None:
                                h_list.append((x,y, self.x*self.y, cont))
                                break
                            elif self.matrix[x+x_v][y+y_v].id == cont.door.id:
                                h_list.append((x+x_v,y+y_v,1,cont))
                        except IndexError:
                            pass


        # going from every empty space to every kind of block
        while len(h_list) != 0:
            # [kitchen, sanitary, common]
            x_h,y_h,dist_h,h_id = h_list.pop()

            dis_x = self.matrix.shape[1]
            dis_y = self.matrix.shape[0]
            shortest = [dis_x*dis_y, dis_x*dis_y,dis_x*dis_y]
            visited = np.zeros((dis_y, dis_x))
            stack=[]

            stack.append((x_h,y_h,dist_h))
            while stack:
                x,y,dist = stack.pop()
                visited[x][y] = 1
                for dx, dy in [(-1, 0), (1, 0), (0, 1), (0, -1)]:
                    if (x + dx) < 0 or (y + dy) < 0:
                        continue
                    try:
                        if visited[x + dx][y + dy] == 0:
                            if self.matrix[x + dx][y + dy].type == '0':
                                stack.append((x + dx,y + dy, dist+1))
                                visited[x + dx][y + dy] = 1

                            elif self.matrix[x + dx][y + dy].door == None:
                                if self.matrix[x + dx][y + dy].type == 'K':
                                    if shortest[0] > dist:
                                        shortest[0] = dist
                                    visited[x + dx][y + dy] = 1
                                elif self.matrix[x + dx][y + dy].type == 'S':
                                    if shortest[1] > dist:
                                        shortest[1] = dist
                                    visited[x + dx][y + dy] = 1
                                elif self.matrix[x + dx][y + dy].type == 'C':
                                    if shortest[2] > dist:
                                        shortest[2] = dist
                                    visited[x + dx][y + dy] = 1

                            elif self.matrix[x + dx][y + dy].door.id == self.matrix[x][y].id:
                                if self.matrix[x + dx][y + dy].type == 'K':
                                    if shortest[0] > dist:
                                        shortest[0] = dist
                                    visited[x + dx][y + dy] = 1
                                elif self.matrix[x + dx][y + dy].type == 'S':
                                    if shortest[1] > dist:
                                        shortest[1] = dist
                                    visited[x + dx][y + dy] = 1
                                elif self.matrix[x + dx][y + dy].type == 'C':
                                    if shortest[2] > dist:
                                        shortest[2] = dist
                                    visited[x + dx][y + dy] = 1
                    except IndexError:
                        pass
            shortest_paths.append((h_id,shortest))
        return shortest_paths






if __name__ == '__main__':
    matrix1 =[
        [1,0,1,0,1],
       [-1,1,0,1,0],
        [1,0,1,0,1],
        [0,1,0,1,0],
        [0,1,0,1,0]]
    matrix2 = [
        [1,1,1,1,1],
       [-1,0,1,0,1],
        [1,0,1,0,1],
        [1,0,0,0,1],
        [1,0,0,0,1],
        [1,1,1,1,1]]
    matrix3 = [
        [1,0,1,0,1],
       [-1,0,1,0,1],
        [1,0,1,0,1],
        [1,0,0,0,1],
        [1,0,1,0,1]]
    matrix4 = [
        [1,1,1,1,1],
       [-1,0,1,0,1],
        [1,0,1,1,1],
        [1,0,1,0,1],
        [1,0,1,0,1],
        [1,1,1,1,1]]
    house1 = House(7,7)
    print(house1.check_connectivity_subgraphs())
    visualize(house1,showIDs=True)

    # house2 = House(5,5, matrix=matrix2)
    # print(loss_function1(house2))
    #
    # house3 = House(5,5, matrix=matrix3)
    # print(loss_function1(house3))
    #
    # house4 = House(5,5, matrix=matrix4)
    # print(loss_function1(house4))
