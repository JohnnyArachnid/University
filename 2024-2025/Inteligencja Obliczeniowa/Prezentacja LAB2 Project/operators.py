import deap.tools

from representation import House
from visualization import visualize
import random
from deap import creator, base, tools

def copy_parent(parent: House): # Helper function to copy parents to children
    rows, cols = parent.matrix.shape[1], parent.matrix.shape[0]
    child = House(parent.x, parent.y)

    for i in range(rows):  # Copy parent to children
        for j in range(cols):
            child.matrix[i][j] = parent.matrix[i][j]
    
    return child

def mutate_individual(house):
    '''
    A mutation that randomly changes the type of one container in the matrix.
    '''
    individual = house[0]
    x = random.randint(0, individual.matrix.shape[1]-1)
    y = random.randint(0, individual.matrix.shape[0]-1)
    cont = individual.matrix[x][y]
    if cont.type != '0':  # We don't mutate container type path
        possible_types = ['K', 'S', 'C', 'H']
        possible_types.remove(cont.type)  # We delete current type for not duplication him
        cont.type = random.choice(possible_types)
    individual.validate_doors()
    return individual,

def mutate_rotate_segment(house):
    '''
    A mutation that rotates a square matrix segment by 90 degrees,
    ensuring that paths ('type == 0') stay in their original positions.
    '''
    individual = house[0]
    size = 3  # Size of the rotated square segment
    start_x = random.randint(0, individual.x - size + 1)
    start_y = random.randint(0, individual.y - size + 1)
    segment = [row[start_x:start_x + size] for row in individual.matrix[start_y:start_y + size]]
    rotated = list(zip(*segment[::-1])) # Rotate the segment by 90 degrees

    for i in range(size):
        for j in range(size):
            original = segment[i][j]
            rotated_container = rotated[i][j]
            if original.type == '0':
                individual.matrix[start_y + i][start_x + j].type = original.type
            else:
                if rotated_container.type != '0':
                    individual.matrix[start_y + i][start_x + j].type = rotated_container.type
    individual.validate_doors()
    return individual,

def mutation_row_or_column(house):
    '''
    A mutation that randomly changes the whole row or column.
    '''
    individual = house[0]
    rows, cols =  individual.matrix.shape[1], individual.matrix.shape[0]
    is_row = random.choice([True, False])  # Drawing random: True = row, False = column
    if is_row:
        row = random.randint(0, rows-1) # Random row mutation
        for col in range(cols):
            cont = individual.matrix[row][col]
            if cont.type != '0':
                possible_types = ['K', 'S', 'C', 'H']
                possible_types.remove(cont.type)
                cont.type = random.choice(possible_types)
    else:
        col = random.randint(0, cols-1) # Random column mutation
        for row in range(rows):
            cont = individual.matrix[row][col]
            if cont.type != '0':
                possible_types = ['K', 'S', 'C', 'H']
                possible_types.remove(cont.type)
                cont.type = random.choice(possible_types)
    individual.validate_doors()
    return individual,

def mutate_add_road(house):
    '''
    A mutation that randomly adds a road (type '0') to the house matrix,
    ensuring that the new road makes sense by being adjacent to at least one other road.
    '''
    individual = house[0]
    rows, cols =  individual.matrix.shape[1], individual.matrix.shape[0]
    valid_positions = []
    option = random.choice([True, False])

    for i in range(rows):
        for j in range(cols):
            if option == True:
                if individual.matrix[i][j].type == 'H':
                    valid_positions.append((i, j))
            else:
                if individual.matrix[i][j].type == '0' and individual.matrix[i][j].id != -1:
                    valid_positions.append((i, j))

    if not valid_positions:  # If no valid positions, do nothing
        return individual

    i, j = random.choice(valid_positions) # Randomly choose one valid position to mutate

    if option == True:
        individual.matrix[i][j].type = '0'
        individual.matrix[i][j].door = None
    else:  # Zmieniamy drogę ('0') na kontener ('H')
        individual.matrix[i][j].type = 'H'

        # Próba przypisania drzwi z sąsiednich dróg
        for dx, dy in [(-1, 0), (1, 0), (0, -1), (0, 1)]:  # Sprawdzamy sąsiadów w czterech kierunkach
            try:
                neighbor = individual.matrix[i + dx][j + dy]
                if neighbor.type == '0' and neighbor.door is not None:  # Sprawdzamy, czy sąsiednia komórka jest drogą z drzwiami
                    if individual.matrix[i][j].door is None:  # Jeśli kontener nie ma przypisanych drzwi
                        individual.matrix[i][j].door = neighbor.door  # Przypisujemy drzwi z sąsiedniego kontenera
                        break  # Po przypisaniu drzwi kończymy sprawdzanie sąsiadów
            except IndexError:
                # Jeśli wyjście poza zakres, ignorujemy ten przypadek
                continue

    individual.validate_doors()  # Walidacja drzwi po mutacji
    return individual

def mutation_special_containers(house):
    '''
    A mutation that randomly changes special containers
    '''
    individual = house[0]
    rows, cols =  individual.matrix.shape[1], individual.matrix.shape[0]
    valid_positions = []

    for i in range(rows):
        for j in range(cols):
            if individual.matrix[i][j].type != '0':
                valid_positions.append((i, j))

    if not valid_positions:  # If no valid positions, do nothing
        individual.validate_doors()
        return individual

    i, j = random.choice(valid_positions) # Randomly choose one valid position to mutate
    possible_types = ['K', 'S', 'C','H']
    cont = individual.matrix[i][j]
    possible_types.remove(cont.type)  # We delete current type for not duplication him
    cont.type = random.choice(possible_types)

    individual.validate_doors()
    return individual

import random

def mutation_change_doors(house):
    individual = house[0]
    rows, cols = individual.matrix.shape[1], individual.matrix.shape[0]
    valid_positions = []

    # Zbieramy wszystkie validne pozycje, gdzie mogą być drzwi
    for i in range(rows):
        for j in range(cols):
            if individual.matrix[i][j].type != '0' and individual.matrix[i][j].door is not None:
                valid_positions.append((i, j))

    # Wybieramy losową pozycję z valid_positions
    if valid_positions:
        x, y = random.choice(valid_positions)
        cont = individual.matrix[x][y]

        # Sprawdzamy sąsiadów, aby zmienić drzwi
        for dx, dy in [(-1, 0), (1, 0), (0, -1), (0, 1)]:  # Sprawdzamy sąsiadów w czterech kierunkach
            try:
                if x + dx < 0 or y + dy < 0:
                    continue
                neighbor = individual.matrix[x + dx][y + dy]
                if neighbor.type == '0':
                    cont.door = neighbor
                    return individual
            except IndexError:
                # Jeśli wyjście poza zakres, ignorujemy ten przypadek
                pass

    individual.validate_doors()  # Walidacja drzwi
    return individual

def crossover_swap_row_or_column(house1, house2):
    '''
    A crossover that swaps random row or column between parents,
    ignoring containers of type '0'.
    '''
    parent1, parent2 = house1[0], house2[0]
    rows, cols = parent1.matrix.shape[1], parent1.matrix.shape[0]
    child1 = copy_parent(parent1)
    child2 = copy_parent(parent2)

    is_row = random.choice([True, False])  # Random choice: True = swap rows, False = swap columns

    if is_row:
        randomRow = random.randint(0, rows-1)
        for j in range(cols):
            if parent1.matrix[randomRow][j].type != '0' and parent2.matrix[randomRow][j].type != '0':
                child1.matrix[randomRow][j].type = parent2.matrix[randomRow][j].type
                child2.matrix[randomRow][j].type = parent1.matrix[randomRow][j].type
    else:
        randomCol = random.randint(0, cols-1)
        for i in range(rows):
            if parent1.matrix[i][randomCol].type != '0' and parent2.matrix[i][randomCol].type != '0':
                child1.matrix[i][randomCol].type = parent2.matrix[i][randomCol].type
                child2.matrix[i][randomCol].type = parent1.matrix[i][randomCol].type
    child1.validate_doors()
    child2.validate_doors()
    return child1, child2

def crossover_chessboard(house1, house2):
    '''
    A crossover that swaps cells between parents in a chessboard pattern,
    ignoring containers of type '0'.
    '''
    parent1, parent2 = house1[0], house2[0]
    rows, cols = parent1.matrix.shape[1], parent1.matrix.shape[0]
    child1 = copy_parent(parent1)
    child2 = copy_parent(parent2)

    for i in range(rows):
        for j in range(cols):
            if parent1.matrix[i][j].type != '0' and parent2.matrix[i][j].type != '0':
                if (i + j) % 2 == 0:  # Chessboard pattern
                    child1.matrix[i][j].type = parent2.matrix[i][j].type
                    child2.matrix[i][j].type = parent1.matrix[i][j].type
    child1.validate_doors()
    child2.validate_doors()
    return child1, child2

def crossover_diagonal(house1, house2):
    '''
    A crossover that swaps values along the main or secondary diagonal,
    ignoring containers of type '0'.
    '''
    parent1, parent2 = house1[0], house2[0]
    rows, cols = parent1.matrix.shape[1], parent1.matrix.shape[0]
    child1 = copy_parent(parent1)
    child2 = copy_parent(parent2)

    if random.random() < 0.5:  # Main diagonal
        for i in range(min(rows, cols)):
            if child1.matrix[i][i].type != '0' and child2.matrix[i][i].type != '0':
                child1.matrix[i][i].type, child2.matrix[i][i].type = child2.matrix[i][i].type, child1.matrix[i][i].type
    else:  # Secondary diagonal
        for i in range(min(rows, cols)):
            if child1.matrix[i][cols - i - 1].type != '0' and child2.matrix[i][cols - i - 1].type != '0':
                child1.matrix[i][cols - i - 1].type, child2.matrix[i][cols - i - 1].type = child2.matrix[i][cols - i - 1].type, child1.matrix[i][cols - i - 1].type
    child1.validate_doors()
    child2.validate_doors()
    return child1, child2


def sel_roulette_inverted(population, placeholder = None):
    # Step 1: Compute max fitness in the population
    max_fitness = max(ind.fitness.values[0] for ind in population)

    # Step 2: Invert fitness values
    for ind in population:
        ind.fitness.values = (max_fitness - ind.fitness.values[0],)

    # Step 3: Apply roulette wheel selection
    selected = tools.selRoulette(population, len(population))

    # Step 4: Restore original fitness values
    for ind in population:
        ind.fitness.values = (max_fitness - ind.fitness.values[0],)

    return selected

# Funkcje do selekcji wbudowane z DEAP
# tools.selBest
# tools.selTournament
# tools.selRoulette