class Solution:
    def rearrangeArray(self, nums: List[int]) -> List[int]:
        n = len(nums)

        ans = [0 for i in range(n)]
        pos, neg = 0, 1
        for i in nums:
            if i < 0:
                ans[neg] = i
                neg += 2
            else:
                ans[pos] = i
                pos += 2
        return ans
