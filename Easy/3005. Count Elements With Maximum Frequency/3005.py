from collections import defaultdict

class Solution:
    def maxFrequencyElements(self, nums: List[int]) -> int:
        d = defaultdict(int)
        maxi = 0
        for i in nums:
            d[i] += 1
            maxi = max(maxi, d[i])
            
        res = 0
        for i in d:
            if d[i] == maxi:
                res += maxi
        return res