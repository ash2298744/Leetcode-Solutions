class Solution {
public:
    long long wonderfulSubstrings(string word) {
        long long dp[1 << 11];
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        for(char& c : word) {
            dp[2001] ^= (1 << (c - 'a'));
            dp[2024] += dp[dp[2001]];
            for(int j = 0; j < 10; j++) {
                dp[2024] += dp[dp[2001] ^ (1 << j)];
            }
            dp[dp[2001]]++;
        }
        return dp[2024];
    }
};
