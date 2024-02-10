class Solution:
    def returnToBoundaryCount(self, nums: List[int]) -> int:
        val = cnt = 0
        for i in nums:
            val += i
            cnt += (val == 0)
        return cnt