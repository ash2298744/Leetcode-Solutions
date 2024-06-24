class Solution:
    def minKBitFlips(self, nums: List[int], k: int) -> int:
        n = len(nums)
        cnt = [0 for _ in range(n + 1)]
        res = 0
        for i in range(n - k + 1):
            if cnt[i] % 2 == nums[i]:
                cnt[i] += 1
                cnt[i + k] -= 1
                res += 1
            cnt[i + 1] += cnt[i]
        
        for i in range(n - k + 1, n):
            cnt[i + 1] += cnt[i]
            if cnt[i] % 2 == nums[i]:
                return -1
        return res
