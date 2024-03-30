#include<bits/stdc++.h>;
using namespace std;

class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n + 1, 0);
        for (int i = n - 1; i >= 0; --i) {
            int maxi = 0;
            for (int j = i; j < n; j++) {
                maxi = max(maxi, arr[j]);
                if ((j - i + 1) <= k)
                    dp[i] = max(dp[i], maxi * (j - i + 1) + dp[j + 1]);
            }
        }
        return dp[0];
    }
};