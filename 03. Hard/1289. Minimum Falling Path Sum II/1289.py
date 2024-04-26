class Solution:
    def minFallingPathSum(self, grid: List[List[int]]) -> int:
        n=len(grid)
        dp=[[inf for i in range(n+1)] for i in range(n+1)]

        for i in range(n):
            dp[n-1][i]=grid[n-1][i]

        for i in range(n-2,-1,-1):
            for j in range(n-1,-1,-1):
                for k in range(n):
                    if j!=k:
                        dp[i][j]=min(dp[i][j],grid[i][j]+dp[i+1][k])
        return min(dp[0])
    