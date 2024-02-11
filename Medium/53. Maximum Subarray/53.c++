#include<bits/stdc++.h>;
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = INT_MIN, val = 0;
        for(auto i : nums) {
            val += i;
            ans = max(ans, val);
            val = max(val, 0);
        }
        return ans;
    }
};