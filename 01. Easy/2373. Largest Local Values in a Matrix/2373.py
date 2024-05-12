class Solution:
    def largestLocal(self, grid: List[List[int]]) -> List[List[int]]:
        row, col = len(grid), len(grid[0])
        res = [[0 for _ in range(col - 2)] for _ in range(row - 2)]
        for i in range(row - 2):
            for j in range(col - 2):
                mx = 0
                for ii in range(i, i + 3):
                    for jj in range(j, j + 3):
                        mx = max(mx, grid[ii][jj])
                res[i][j] = mx
        return res
