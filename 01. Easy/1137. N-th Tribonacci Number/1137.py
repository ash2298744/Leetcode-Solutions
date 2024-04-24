class Solution:
    def tribonacci(self, n: int) -> int:
        dp = [0 for i in range(n + 3)]
        dp[1] = dp[2] = 1
        for i in range(3, n + 1):
            dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3]
        return dp[n]
