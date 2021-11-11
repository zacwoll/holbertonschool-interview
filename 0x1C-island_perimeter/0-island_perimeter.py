#!/usr/bin/python3
"""
0-island_perimeter
"""


def island_perimeter(grid):
    """
    Returns the perimeter of the island
    """
    h, w = len(grid), len(grid[0])

    if h * w == 0:
        # Quick response for simple case
        return 0

    land_cell, internal_edge = 0, 0

    # scan each cell from top to bottom, from left to right
    for y in range(h):
        for x in range(w):

            if grid[y][x] == 1:
                # current cell is land
                land_cell += 1

                if y and grid[y-1][x]:
                    # current land cell share one internal edge
                    # with neighbor land cell on the top
                    internal_edge += 1

                if x and grid[y][x-1]:
                    # current land cell share one internal edge with neighbor
                    # land cell of the left
                    internal_edge += 1

    # each land cell contributes 4 edge
    # each internal edge is repeatedly counted by 2 adjacent land cells
    perimeter = land_cell * 4 - internal_edge * 2

    return perimeter
