class Solution:
    def longestIdealString(self, s: str, k: int) -> int:
        n = len(s)
        dp = [[0 for _ in range(27)] for _ in range(n + 1)]
        for i in range(n - 1, -1, -1):
            for prev in range(27):
                dp[i][prev] = max(dp[i][prev], dp[i + 1][prev])
                if prev == 26 or abs(ord(s[i]) - prev - 97) <= k:
                    dp[i][prev] = max(dp[i][prev], 1 + dp[i + 1][ord(s[i]) - 97])
        return dp[0][26]
