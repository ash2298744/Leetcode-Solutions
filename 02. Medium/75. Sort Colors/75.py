class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        z = o = 0
        for i in nums:
            if i == 0:
                z += 1
            elif i == 1:
                o += 1
        
        for i in range(len(nums)):
            if z:
                nums[i] = 0
                z -= 1
            elif o:
                nums[i] = 1
                o -= 1
            else:
                nums[i] = 2
        