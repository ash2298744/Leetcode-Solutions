#include<bits/stdc++.h>;
using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<int>> dp(n, vector<int>(++k + 1, 10000000));
        dp[src][0] = 0;
        for(int i = 1; i <= k; i++) {
            for(auto j : flights) {
                dp[j[1]][i] = min(dp[j[1]][i], dp[j[0]][i - 1] + j[2]);
            }
        }
        int cheap = 10000000;
        for(int i = 1; i <= k; i++) cheap = min(cheap, dp[dst][i]);
        return cheap == 10000000 ? -1 : cheap;
    }
};
