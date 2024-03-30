class Solution:
    def minimumCost(self, nums: List[int]) -> int:
        ans = float("inf")
        for i in range(1, len(nums) - 1):
            for j in range(i + 1, len(nums)):
                ans = min(ans, nums[0] + nums[i] + nums[j])
        return ans