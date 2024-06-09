class Solution:
    def subarraysDivByK(self, nums: List[int], k: int) -> int:
        dp = {0 : 1}
        val = cnt = 0
        for i in nums:
            val = (val + i) % k
            if val in dp:
                cnt += dp[val]
            else:
                dp[val] = 0
            dp[val] += 1
        return cnt
