class Solution:
    def numSubarrayProductLessThanK(self, nums: List[int], k: int) -> int:
        n, cnt, j, pref = len(nums), 0, 0, 1
        for i in range(n):
            pref = pref * nums[i]
            while j <= i and pref >= k:
                pref = pref // nums[j]
                j += 1
            cnt += (i - j + 1)
        return cnt
    