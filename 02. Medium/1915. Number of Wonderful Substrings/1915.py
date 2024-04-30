class Solution:
    def wonderfulSubstrings(self, word: str) -> int:
        dp = [0 for _ in range(1 << 11)]
        dp[0] = 1
        for i in word:
            dp[2001] ^= (1 << (ord(i) - 97))
            dp[2024] += dp[dp[2001]]
            for j in range(10):
                dp[2024] += dp[dp[2001] ^ (1 << j)]
            dp[dp[2001]] += 1
        return dp[2024]
