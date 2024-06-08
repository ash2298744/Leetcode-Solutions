class Solution:
    def checkSubarraySum(self, nums: List[int], k: int) -> bool:
        dp = {0 : -1}
        val = 0
        for i in range(len(nums)):
            val = (val + nums[i]) % k
            if val in dp:
                if (i - dp[val]) >= 2:
                    return True
            else:
                dp[val] = i
        return False
        