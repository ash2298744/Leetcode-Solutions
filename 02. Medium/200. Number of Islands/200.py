class Solution:
    def dfs(self, x, y, row, col, grid, vis):
        if (x < 0 or x == row or y == col or y < 0 or (x, y) in vis or grid[x][y] == "0"): return
        vis.add((x, y))
        self.dfs(x + 1, y, row, col, grid, vis)
        self.dfs(x, y + 1, row, col, grid, vis)
        self.dfs(x - 1, y, row, col, grid, vis)
        self.dfs(x, y - 1, row, col, grid, vis)

    def numIslands(self, grid: List[List[str]]) -> int:
        vis = set()
        row, col = len(grid), len(grid[0])
        islands = 0
        for i in range(row):
            for j in range(col):
                if grid[i][j] == "1" and (i, j) not in vis:
                    islands += 1
                    self.dfs(i, j, row, col, grid, vis)
        return islands
