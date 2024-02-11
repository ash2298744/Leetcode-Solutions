class Solution:
    def maxSubArray(self, nums):
        ans, val = float("-inf"), 0
        for i in nums:
            val += i
            ans = max(ans, val)
            val = max(val, 0)
        return ans