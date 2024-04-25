class Solution {
public:
    int longestIdealString(string s, int k) {
        int n = s.size();
        vector<vector<int>> dp(n + 1, vector<int>(27, 0));
        for(int i = n - 1; i >= 0; i--) {
            for(int prev = 0; prev < 27; prev++) {
                dp[i][prev] = max(dp[i][prev], dp[i + 1][prev]);
                if(prev == 26 || abs((int)s[i] - prev - 97) <= k) {
                    dp[i][prev] = max(dp[i][prev], 1 + dp[i + 1][(int)s[i] - 97]);
                }
            }
        }
        return dp[0][26];
    }
};
