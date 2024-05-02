class Solution:
    def findMaxK(self, nums: List[int]) -> int:
        seen = set()
        ans = -1
        for i in nums:
            if -i in seen:
                ans = max(ans, abs(i))
            seen.add(i)
        return ans
        