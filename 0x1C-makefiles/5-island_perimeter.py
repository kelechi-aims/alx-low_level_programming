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
                if grid[i - 1][j] == 0:
                    perimeter += 1
                if grid[i + 1][j] == 0:
                    perimeter += 1
                if grid[i][j - 1] == 0:
                    perimeter += 1
                if grid[i][j + 1] == 0:
                    perimeter += 1
    return perimeter
