class Solution:
    def findMaxLength(self, nums: List[int]) -> int:
        dp = defaultdict(int)
        dp[0] = -1
        ans = val = 0
        for i in range(len(nums)):
            val += 1 if nums[i] else -1
            if val in dp: 
                ans = max(ans, i - dp[val])
            else: 
                dp[val] = i
        return ans
        