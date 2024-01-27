#include<bits/stdc++.h>;
using namespace std;

class Solution {
    int MOD = 1e9 + 7;
    
public:
    int outOfBoundPaths(int i, int j, int move, int m, int n, int maxMove, vector<vector<int>> dircn, vector<vector<vector<int>>>& dp) {
        if (dp[i][j][move] != -1) return dp[i][j][move];
        int cnt = 0;
        for (auto k : dircn) {
            if ((move + 1) <= maxMove) {
                if ((k[0] + i) >= 0 && (k[1] + j) >= 0 && (k[0] + i) < m && (k[1] + j) < n) {
                    cnt = (cnt + outOfBoundPaths(i + k[0], j + k[1], move + 1, m, n, maxMove, dircn, dp)) % MOD;
                } else cnt++;
            }
        }
        dp[i][j][move] = cnt % MOD;
        return cnt;
    }

    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>> dp(m + 1, vector<vector<int>>(n + 1, vector<int>(maxMove + 1, -1)));
        vector<vector<int>> dircn = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        return outOfBoundPaths(startRow, startColumn, 0, m, n, maxMove, dircn, dp);
    }
};