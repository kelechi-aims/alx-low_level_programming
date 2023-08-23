#!/usr/bin/python3
"""
This module has the island_perimeter function.
"""


def island_perimeter(grid):
    """
    Calculates the perimeter of an island described by the grid.

    Args:
    grid (List[List[int]]): A list of lists where 0 represent water
    and 1 represnts land.

    Returns:
    int: The perimeter of the island.
    """

    perimeter = 0
    for i in range(len(grid)):
        for j in range(len(grid[i])):
            if grid[i][j] == 1:
                perimeter += 4
                if i > 0 and grid[i - 1][j] == 1:
                    perimeter -= 2
                if j > 0 and grid[i][j - 1] == 1:
                    perimeter -= 2
    return perimeter
