class Solution {
public:
    bool checkValidString(string s) {
        int n = s.size();

        int dp[n + 1][n + 1][n + 1];
        memset(dp, 0, sizeof(dp));

        for(int i = 0; i <= n; i++) 
            dp[n][i][i] = 1;

        for(int i = n - 1; i >= 0; i--) {
            for(int o = n - 1; o >= 0; o--) {
                for(int c = n - 1; c >= 0; c--) {
                    if(s[i] == '(') {
                        if(o + 1 >= c) dp[i][o][c] |= dp[i + 1][o + 1][c];
                    } else if(s[i] == ')') {
                        if(o >= c + 1) dp[i][o][c] |= dp[i + 1][o][c + 1];
                    } else {
                        dp[i][o][c] |= dp[i + 1][o][c];
                        if(o + 1 >= c) dp[i][o][c] |= dp[i + 1][o + 1][c];
                        if(o >= c + 1) dp[i][o][c] |= dp[i + 1][o][c + 1];
                    }
                }
            }
        }
        return dp[0][0][0];
    }
};

