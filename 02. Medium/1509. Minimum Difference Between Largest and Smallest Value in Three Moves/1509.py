class Solution:
    def minDifference(self, nums: List[int]) -> int:
        if len(nums) < 4: return 0
        arr = sorted(nums)
        ans, n = inf, len(nums)
        for i in range(4):
            left = arr[i]
            right = max(arr[n - (4 - i)], left)
            ans = min(ans, right - left)
        return ans