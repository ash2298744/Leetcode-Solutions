#include<bits/stdc++.h>;
using namespace std;

class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int ans = INT_MAX, n = nums.size();
        for(int i = 1; i < n - 1; i++) {
            for(int j = i + 1; j < n; j++) {
                ans = min(ans, nums[0] + nums[i] + nums[j]);
            }
        }
        return ans;
    }
};