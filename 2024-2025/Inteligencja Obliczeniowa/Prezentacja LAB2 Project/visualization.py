import matplotlib.pyplot as plt
from matplotlib.colors import ListedColormap
import matplotlib.patches as mpatches
from matplotlib.lines import Line2D

def visualize(house, showIDs=False):
    '''
    Improved matrix visualization using imshow.
    '''
    # Define color mappings and numerical values for imshow
    colors = {
        'K': '#A0AF92',  # Kitchen
        'S': '#E84C59',  # Sanitary room
        'C': '#FEECCC',  # Common space
        'H': '#DDCCB5',  # House
        '0': '#DFDFDF'   # Empty space
    }
    # Assign a numeric index to each container type
    color_mapping = {container: idx for idx, container in enumerate(colors)}
    
    # matrix returns data: type/id>door
    # Scrape container type
    typeMatrix = [[str(cell)[0] for cell in row] for row in house.matrix]
    #Scrape container id
    idMatrix = [[str(cell)[2:].split('>')[0] for cell in row] for row in house.matrix]
    # Scrape type of container the doors are leading to 
    dtypeMatrix = [[str(cell).split('>')[1].split('/')[0] if '>' in str(cell) else 'none' for cell in row] for row in house.matrix]
    # Scrape id of container the doors are leading to
    didMatrix = [[(str(cell).split('>')[1].split('/')[1] 
               if '>' in str(cell) and '/' in str(cell).split('>')[1] 
               else 'none') 
              for cell in row] 
             for row in house.matrix]
    
    # Convert the type matrix into numeric indices for imshow
    numeric_matrix = [[color_mapping[cell] for cell in row] for row in typeMatrix]

    # Create colormap for imshow
    cmap = ListedColormap([colors[key] for key in colors])

    # Plot using imshow
    fig, ax = plt.subplots()
    img = ax.imshow(numeric_matrix, cmap=cmap)

    # Optionally display container IDs in the center of the cells
    for y in range(len(typeMatrix)):
            for x in range(len(typeMatrix[y])):
                # Draw outlines of containers
                if typeMatrix[y][x] != '0':  # Skip empty spaces
                    ax.plot([x - 0.5, x + 0.5], [y - 0.5, y - 0.5], color='#4C4C4C', lw=1.5)  # Upper edge
                    ax.plot([x - 0.5, x + 0.5], [y + 0.5, y + 0.5], color='#4C4C4C', lw=1.5)  # Lower edge
                    ax.plot([x - 0.5, x - 0.5], [y - 0.5, y + 0.5], color='#4C4C4C', lw=1.5)  # Left edge
                    ax.plot([x + 0.5, x + 0.5], [y - 0.5, y + 0.5], color='#4C4C4C', lw=1.5)  # Right edge

                    # Draw doors
                    if(didMatrix[y][x] != 'none'): # Skip none values

                        door_width = 0.2  # Width of the door
                        # Check for doors between adjacent cells (left, right, top, and bottom)
                        if x > 0:  # Check left neighbor
                            if didMatrix[y][x] == idMatrix[y][x - 1]:  # Same type of container
                                ax.plot([x - 0.5, x - 0.5], [y - door_width, y + door_width], color='#664202', lw=3)  # Draw door line (vertical)

                        if x < len(typeMatrix[y]) - 1:  # Check right neighbor
                            if didMatrix[y][x] == idMatrix[y][x + 1]:  # Same type of container
                                ax.plot([x + 0.5, x + 0.5], [y - door_width, y + door_width], color='#664202', lw=3)  # Draw door line (vertical)

                        if y > 0:  # Check top neighbor
                            if didMatrix[y][x] == idMatrix[y - 1][x]:  # Same type of container
                                ax.plot([x - door_width, x + door_width], [y - 0.5, y - 0.5], color='#664202', lw=3)  # Draw door line (horizontal)

                        if y < len(typeMatrix) - 1:  # Check bottom neighbor
                            if didMatrix[y][x] == idMatrix[y + 1][x]:  # Same type of container
                                ax.plot([x - door_width, x + door_width], [y + 0.5, y + 0.5], color='#664202', lw=3)  # Draw door line (horizontal)
                
                if showIDs:
                    ax.text(x, y, f'{idMatrix[y][x]}', ha='center', va='center', color='black', fontsize=12)
                

                # Check for Main doors (represented by -1) on the edge of the matrix
                if idMatrix[y][x] == '-1':  # If the cell value is -1, it represents a door

                    door_width = 0.2  # Width of the door

                    if x == 0:  # Left edge
                        ax.plot([x - 0.5, x - 0.5], [y - door_width, y + door_width], color='#664202', lw=5)  # Vertical door line
                    if x == len(typeMatrix[y]) - 1:  # Right edge
                        ax.plot([x + 0.5, x + 0.5], [y - door_width, y + door_width], color='#664202', lw=5)  # Vertical door line
                    if y == 0:  # Top edge
                        ax.plot([x - door_width, x + door_width], [y - 0.5, y - 0.5], color='#664202', lw=5)  # Horizontal door line
                    if y == len(typeMatrix) - 1:  # Bottom edge
                        ax.plot([x - door_width, x + door_width], [y + 0.5, y + 0.5], color='#664202', lw=5)  # Horizontal door line

    # Create a legend
    legend = [
        mpatches.Patch(color=colors['K'], label="Kuchnia"), 
        mpatches.Patch(color=colors['S'], label="Pokój Sanitarny"), 
        mpatches.Patch(color=colors['C'], label="Przestrzeń Wspólna"),
        mpatches.Patch(color=colors['H'], label="Mieszkanie"),
        mpatches.Patch(color=colors['0'], label="Pusta Przestrzeń")
    ]

    door_line = Line2D([0], [0], color='#664202', lw=2, label="Drzwi")
    legend.append(door_line)

    plt.legend(handles=legend, loc='upper left', bbox_to_anchor=(1, 1), fontsize=10, title="Legenda")

    # Remove axis ticks for a cleaner look
    ax.set_xticks([])
    ax.set_yticks([])
    ax.set_aspect('equal')
    plt.title("Wizualizacja Rozmieszczenia Kontenerów")
    plt.tight_layout()
    plt.show()