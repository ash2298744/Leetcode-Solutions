class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        O = K = 0
        for i in range(len(nums)):
            O += (i + 1)
            K += nums[i]
        return O - K