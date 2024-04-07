class Solution:
    def checkValidString(self, s: str) -> bool:
        n = len(s)

        dp = [[[False for i in range(n + 1)] for i in range(n + 1)] for i in range(n + 1)]

        for i in range(n + 1):
            dp[n][i][i] = True
        
        for i in range(n - 1, -1, -1):
            for o in range(n - 1, -1, -1):
                for c in range(n - 1, -1, -1):
                    if s[i] == '(':
                        if (o + 1) >= c:
                            dp[i][o][c] = dp[i][o][c] | dp[i + 1][o + 1][c]
                    elif s[i] == ')':
                        if o >= (c + 1):
                            dp[i][o][c] = dp[i][o][c] | dp[i + 1][o][c + 1]
                    else:
                        dp[i][o][c] = dp[i][o][c] | dp[i + 1][o][c]
                        if (o + 1) >= c:
                            dp[i][o][c] = dp[i][o][c] | dp[i + 1][o + 1][c]
                        if o >= (c + 1):
                            dp[i][o][c] = dp[i][o][c] | dp[i + 1][o][c + 1]
        return dp[0][0][0]
        