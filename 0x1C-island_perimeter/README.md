# 0x1C. Island Perimeter

Create a function def island_perimeter(grid): that returns the perimeter of the island described in grid:

- grid is a list of list of integers:
  - 0 represents water
  - 1 represents land
  - Each cell is square, with a side length of 1
  - Cells are connected horizontally/vertically (not diagonally).
  - grid is rectangular, with its width and height not exceeding 100
- The grid is completely surrounded by water
- There is only one island (or nothing).
- The island doesn’t have “lakes” (water inside that isn’t connected to the water surrounding the island).

```
guillaume@ubuntu:~/0x1C$ cat 0-main.py
#!/usr/bin/python3
"""
0-main
"""
island_perimeter = __import__('0-island_perimeter').island_perimeter

if __name__ == "__main__":
    grid = [
        [0, 0, 0, 0, 0, 0],
        [0, 1, 0, 0, 0, 0],
        [0, 1, 0, 0, 0, 0],
        [0, 1, 1, 1, 0, 0],
        [0, 0, 0, 0, 0, 0]
    ]
    print(island_perimeter(grid))

guillaume@ubuntu:~/0x1C$ 
guillaume@ubuntu:~/0x1C$ ./0-main.py
12
guillaume@ubuntu:~/0x1C$ 
```

The trick to this exercise is in the perimeter calculation. Everywhere there is a value towards the perimeter, there is a land tile adjacent to either a sea tile or the edge of the grid. So the easy way to solve this equation is to find every land tile and check around it for sea tiles and bounds of the grid. Total the number of tiles where that happens and you have the total_perimeter of the island. The rectangular grid is only a max of 100x100 so there is no need for further optimization, however in the more general case, a more optimized solution may locate the perimeter tiles of the island and calculate as it goes. That solution may look like:
1. Beginning from the top, look for the closest perimeter tile of the island.
2. Save the coordinates of the tile.
3. Traverse the edge of the island, calculating total perimeter as you go until you reach the starting tile, saved from the previous step.
4. Return perimeter
Note that this solution still follows the "no lakes" rule, where inside the island there are zero bodies of water, thus the perimeter of the island is can be calculated without consideration of landlocked sea tiles.