class Solution:
    def sumOfEncryptedInt(self, nums: List[int]) -> int:
        res = 0
        for i in nums:
            maxi = max([int(i) for i in str(i)])
            s = str(maxi) * len(str(i))
            res += int(s)
        return res