class Solution:
    def findDuplicates(self, nums: List[int]) -> List[int]:
        n = len(nums)
        
        for i in range(n):
            curr = nums[i] - 1
            want = i
            while curr != (want) and (nums[curr] - 1) != curr:
                nums[curr], nums[want] = nums[want], nums[curr]
                curr = nums[i] - 1
                want = i

        ans = []
        for i in range(n):
            if nums[i] != (i + 1):
                ans.append(nums[i])
        return ans
