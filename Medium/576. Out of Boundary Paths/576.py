class Solution:
    def findPaths(
        self, m: int, n: int, maxMove: int, startRow: int, startColumn: int) -> int:
        MOD = pow(10, 9) + 7
        dircn = [[1, 0], [0, 1], [-1, 0], [0, -1]]
        dp = [[[-1 for i in range(maxMove + 1)] for i in range(n)] for i in range(m)]

        def outOfBoundaryPaths(i, j, move):
            if dp[i][j][move] != -1:
                return dp[i][j][move]

            cnt = 0
            for k in dircn:
                if (move + 1) <= maxMove:
                    if (
                        (k[0] + i) >= 0
                        and (k[1] + j) >= 0
                        and (k[0] + i) < m
                        and (k[1] + j) < n
                    ):
                        cnt += outOfBoundaryPaths(i + k[0], j + k[1], move + 1)
                    else:
                        cnt += 1

            dp[i][j][move] = cnt % MOD
            return cnt % MOD

        return outOfBoundaryPaths(startRow, startColumn, 0)
