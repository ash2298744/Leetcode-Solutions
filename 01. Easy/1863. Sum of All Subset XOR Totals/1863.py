class Solution:
    def subsetXORSum(self, nums: List[int]) -> int:
        n = len(nums)
        xor = 0
        for i in range(1 << n):
            cur = 0
            for j in range(n):
                if (i >> j) & 1:
                    cur ^= nums[j]
            xor += cur
        return xor
