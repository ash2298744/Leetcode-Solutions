class Solution:
    def checkRecord(self, n: int) -> int:
        MOD = 10 ** 9 + 7
        dp = [[[0 for _ in range(3)] for _ in range(2)] for _ in range(n + 1)]

        for A in range(2):
            for L in range(3):
                dp[n][A][L] = 1

        for P in range(n - 1, -1, -1):
            for A in range(2):
                for L in range(3):
                    if A < 1: dp[P][A][L] = (dp[P][A][L] + dp[P + 1][A + 1][0]) % MOD
                    if L < 2: dp[P][A][L] = (dp[P][A][L] + dp[P + 1][A][L + 1]) % MOD
                    dp[P][A][L] = (dp[P][A][L] + dp[P + 1][A][0]) % MOD
        return dp[0][0][0]
