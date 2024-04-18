class Solution:
    def islandPerimeter(self, grid: List[List[int]]) -> int:
        row, col = len(grid), len(grid[0])

        grid = [[0 for i in range(col)]] + grid
        grid = grid + [[0 for i in range(col)]]

        for i in range(row + 2):
            grid[i] = [0] + grid[i] + [0]

        row, col = row + 2, col + 2
        perimeter = 0
        for i in range(row):
            for j in range(col):
                if grid[i][j] == 0:
                    for dx, dy in [[1, 0], [0, 1], [-1, 0], [0, -1]]:
                        if (i + dx) >= 0 and (j + dy) >= 0 and (i + dx) < row and (j + dy) < col and grid[i + dx][j + dy]:
                            perimeter += 1
        return perimeter
     