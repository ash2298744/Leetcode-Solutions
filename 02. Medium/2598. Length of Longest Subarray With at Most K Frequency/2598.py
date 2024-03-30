class Solution:
    def maxSubarrayLength(self, nums: List[int], k: int) -> int:
        d = defaultdict(int)
        ans = j = 0
        for i in range(len(nums)):
            d[nums[i]] += 1

            while d[nums[i]] > k:
                d[nums[j]] -= 1
                j += 1

            ans = max(ans, i - j + 1)
        return ans
