class Solution:
    def largestPerimeter(self, nums: List[int]) -> int:
        nums.sort()

        pref = [0]
        for i in nums:
            pref.append(pref[-1] + i)
            
        for i in range(len(nums) - 1, -1, -1):
            if nums[i] < pref[i]:
                if (i + 1) >= 3:
                    return pref[i + 1]
        return -1
