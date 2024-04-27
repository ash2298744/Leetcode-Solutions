class Solution {
public:
    int solve(int curr, int i, int r, int k, string& ring, string& key, vector<vector<int>>& dp) {
        if(i == k) return k;
        if(dp[curr][i] != -1) return dp[curr][i];
        int op = INT_MAX;
        for(int j = 0; j < r; j++) {
            if(ring[j] == key[i]) {
                int mini;
                if (j > curr) {
                    mini = min(abs(j - curr), r + curr - j);
                } else mini = min(abs(j - curr), r - curr + j);
                op = min(op, mini + solve(j, i + 1, r, k, ring, key, dp));
            }   
        }
        return dp[curr][i] = op;
    }

    int findRotateSteps(string ring, string key) {
        int r = ring.size(), k = key.size();
        vector<vector<int>> dp(r + 1, vector<int>(k + 1, -1));
        return solve(0, 0, r, k, ring, key, dp);
    }
};
