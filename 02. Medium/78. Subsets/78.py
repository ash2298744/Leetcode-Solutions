class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        n = len(nums)
        res = []
        for i in range(1 << n):
            cur = []
            for j in range(n):
                if (i >> j) & 1:
                    cur.append(nums[j])
            res.append(cur)
        return res
