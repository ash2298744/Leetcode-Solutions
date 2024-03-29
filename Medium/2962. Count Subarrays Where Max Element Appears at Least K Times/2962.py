class Solution:
    def countSubarrays(self, nums: List[int], k: int) -> int:
        n, maxi, maxiFreq, maxiCnt, j = len(nums), max(nums), 0, 0, 0
        for i in range(n):
            maxiFreq += (nums[i] == maxi)
            while j <= i and maxiFreq == k:
                maxiFreq -= (nums[j] == maxi)
                j += 1
            maxiCnt += (i - j + 1)
        return (n * (n + 1)) // 2 - maxiCnt
