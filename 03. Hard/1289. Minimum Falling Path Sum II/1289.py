class Solution:
    def minFallingPathSum(self, grid: List[List[int]]) -> int:
        n = len(grid)
        
        curr = [inf for _ in range(n + 1)]
        nxt = [inf for _ in range(n + 1)]

        for i in range(n):
            curr[i] = grid[n - 1][i]

        for i in range(n - 2, -1, -1):
            for j in range(n - 1, -1, -1):
                for k in range(n):
                    if j != k:
                        curr[j] = min(curr[j], grid[i][j] + nxt[k])
            nxt = [x for x in curr]
        print(nxt)
        return curr[n - 1]
