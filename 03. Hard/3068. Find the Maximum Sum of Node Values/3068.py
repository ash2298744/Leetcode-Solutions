class Solution:
    def maximumValueSum(self, nums: List[int], k: int, edges: List[List[int]]) -> int:
        n = len(nums)
        dp = [[-inf for _ in range(2)] for _ in range(n + 1)]
        dp[n][0] = 0
        for i in range(n - 1, -1, -1):
            for parity in range(2):
                dp[i][parity] = max(dp[i][parity], (nums[i] ^ k) + dp[i + 1][parity ^ 1])
                dp[i][parity] = max(dp[i][parity], nums[i] + dp[i + 1][parity])
        return dp[0][0]
