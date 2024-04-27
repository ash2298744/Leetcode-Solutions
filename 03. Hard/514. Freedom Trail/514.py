class Solution:
    def findRotateSteps(self, ring: str, key: str) -> int:
        r, k = len(ring), len(key)
        dp = [[-1 for _ in range(k + 1)] for _ in range(r + 1)]
        def solve(curr, i):
            if i == k:
                return k

            if dp[curr][i] != -1:
                return dp[curr][i]

            op = inf
            for j in range(r):
                if ring[j] == key[i]:
                    if j > curr:
                        mini = min(abs(j - curr), r + curr - j)
                    else:
                        mini = min(abs(j - curr), r - curr + j)
                    op = min(op, mini + solve(j, i + 1))
            dp[curr][i] = op
            return op

        return solve(0, 0)
