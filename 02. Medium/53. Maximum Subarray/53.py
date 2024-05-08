class Solution:
    def maxSubArray(self, nums):
        ans, val = float("-inf"), 0
        for ii in nums:
            val += ii
            ans = max(ans, val)
            val = max(val, 0)
        return ans