""" 0. Island Perimeter """


def island_perimeter(grid):
    """ return the perimeter of the island described in grid"""
    total_perimeter = 0
    for i, row in enumerate(grid):
        for j, element in enumerate(row):
            if (element == 0):
                continue
            # print(i, j)
            if (j != 0 and row[j - 1] == 0):
                # print('left')
                total_perimeter += 1
            if (j != len(row) - 1 and row[j + 1] == 0):
                # print('right')
                total_perimeter += 1
            if (i != 0 and grid[i - 1][j] == 0):
                # print('up')
                total_perimeter += 1
            if (i != len(grid) - 1 and grid[i + 1][j] == 0):
                # print('down')
                total_perimeter += 1
    return total_perimeter


def print_grid(grid):
    """ display the grid """
    for row in grid:
        print(row)


if __name__ == "__main__":
    grid = [
        [0, 0, 0, 0, 0, 0],
        [0, 1, 0, 0, 0, 0],
        [0, 1, 0, 0, 0, 0],
        [0, 1, 1, 1, 0, 0],
        [0, 0, 0, 0, 0, 0]
    ]
    print_grid(grid)
    print(island_perimeter(grid))
