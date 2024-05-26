class Solution {
public:
    const int MOD = 1e9 + 7;
    int checkRecord(int n) {
        int dp[n + 1][2][3];
        memset(dp, 0, sizeof(dp));

        for(int A = 0; A < 2; A++) {
            for(int L = 0; L < 3; L++) {
                dp[n][A][L] = 1;
            }
        }

        for(int P = n - 1; P >= 0; P--) {
            for(int A = 0; A < 2; A++) {
                for(int L = 0; L < 3; L++) {
                    if(A < 1) dp[P][A][L] = (dp[P][A][L] + dp[P + 1][A + 1][0]) % MOD;
                    if(L < 2) dp[P][A][L] = (dp[P][A][L] + dp[P + 1][A][L + 1]) % MOD;
                    dp[P][A][L] = (dp[P][A][L] + dp[P + 1][A][0]) % MOD;
                }
            }
        }
        return dp[0][0][0];
    }
};
