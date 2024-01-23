class Solution:
    def rob(self, nums: list[int]) -> int:
        dp = [0 for i in range(len(nums) + 2)]
        for i in range(len(nums) - 1, -1, -1):
            dp[i] = max(dp[i + 1], nums[i] + dp[i + 2])
        return dp[0]