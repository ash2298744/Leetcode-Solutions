class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        int n = nums.size();
        vector<vector<long long>> dp(n + 1, vector<long long>(2, 1LL * -1 * 1 << 45));
        dp[n][0] = 0;
        for(int i = n - 1; i >= 0; i--) {
            for(int parity = 0; parity < 2; parity++) {
                dp[i][parity] = max(dp[i][parity], (nums[i] ^ k) + dp[i + 1][parity ^ 1]);
                dp[i][parity] = max(dp[i][parity], nums[i] + dp[i + 1][parity]);
            }
        }   
        return dp[0][0];
    }
};
