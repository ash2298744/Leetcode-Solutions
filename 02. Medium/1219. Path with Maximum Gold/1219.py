class Solution:
    def getMaximumGold(self, grid: List[List[int]]) -> int:
        row, col = len(grid), len(grid[0])
        ans = 0
        def dfs(i, j, gold):
            nonlocal ans
            if(i < 0 or j < 0 or i == row or j == col or grid[i][j] == 0):
                ans = max(ans, gold)
                return
            curr = grid[i][j]
            grid[i][j] = 0
            dfs(i + 1, j, gold + curr)
            dfs(i - 1, j, gold + curr)
            dfs(i, j + 1, gold + curr)
            dfs(i, j - 1, gold + curr)
            grid[i][j] = curr
     
        for i in range(row):
            for j in range(col):
                if grid[i][j]: 
                   dfs(i, j, 0)
        return ans
