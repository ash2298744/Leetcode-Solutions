class Solution:
    def maxSumAfterPartitioning(self, arr: List[int], k: int) -> int: 
        n = len(arr)
        dp = [0 for i in range(n + 1)]
        for i in range(n - 1, -1, -1):
            maxi = 0
            for j in range(i, n):
                if (j - i + 1) <= k:
                    maxi = max(maxi, arr[j])
                    dp[i] = max(dp[i], maxi * (j - i + 1) + dp[j + 1])
        return dp[0]

