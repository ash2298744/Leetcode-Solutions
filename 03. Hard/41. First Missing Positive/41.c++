class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        n = len(nums)
        for i in range(n):
            curr = nums[i] - 1
            want = i
            while curr >= 0 and curr <= n - 1 and curr != want and (nums[curr] - 1) != curr:
                nums[curr], nums[want] = nums[want], nums[curr]
                curr = nums[i] - 1
                want = i
       
        for i in range(n):
            if nums[i] != (i + 1):
                return i + 1
        return n + 1
        