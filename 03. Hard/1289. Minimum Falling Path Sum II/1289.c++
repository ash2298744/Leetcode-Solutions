class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, INT_MAX));

        for (int i = 0; i < n; i++)
            dp[n - 1][i] = grid[n - 1][i];

        for (int i = n - 2; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                for (int k = 0; k < n; k++) {
                    if (k != j)
                        dp[i][j] = min(dp[i][j], grid[i][j] + dp[i + 1][k]);
                }
            }
        }

        int fall = INT_MAX;
        for (int j = 0; j < n; j++)
            fall = min(fall, dp[0][j]);
        return fall;
    }
};