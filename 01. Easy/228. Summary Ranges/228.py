class Solution:
    def summaryRanges(self, nums: List[int]) -> List[str]:
        if len(nums) == 1:
            return [str(nums[0])]
            
        res = []
        n = len(nums)
        i = j = 0
        while j < n - 1:
            while j < n - 1 and nums[j] == nums[j + 1] - 1:
                j += 1

            if i != j:
                res.append(str(nums[i]) + "->" + str(nums[j]))
            else:
                res.append(str(nums[i]))

            j += 1
            i = j

            if j == n - 1:
                res.append(str(nums[j]))
                
        return res
                