class Solution:
    def countSubarrays(self, nums: List[int], minK: int, maxK: int) -> int:
        n = len(nums)
        temp = []
        arr = []
        for i in nums:
            if i >= minK and i <= maxK:
                temp.append(i)
            else:
                arr.append(temp)
                temp = []
        if temp:
            arr.append(temp)
        
        ans = 0
        for o in arr:
            t = len(o)
            i = j = -1
            for k in range(t):
                if o[k] == minK:
                    i = k
                if o[k] == maxK:
                    j = k
                ans += max(0, min(i, j) + 1)
        return ans
        