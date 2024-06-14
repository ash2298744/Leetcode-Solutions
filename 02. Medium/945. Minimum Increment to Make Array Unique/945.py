class Solution:
    def minIncrementForUnique(self, nums: List[int]) -> int:
        nums.sort()
        res = mx = 0
        for i in range(1, len(nums)):
            mx = max(mx, nums[i - 1])
            if nums[i] <= mx:
                mx += 1
                res += abs(nums[i] - mx)
                nums[i] = mx
        return res
        