#include<bits/stdc++.h>;
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size(), prod = 1;

        vector<int> ans(n, 0);
        for(int i = n - 1; i >= 0; i--) {
            prod *= nums[i];
            ans[i] = prod;
        }
        
        prod = 1;
        for(int i = 0; i < n; i++) {
            if(i == 0) ans[i] = ans[i + 1];
            else if(i == n - 1) ans[i] = prod;
            else ans[i] = prod * ans[i + 1];
            prod *= nums[i];
        }
        return ans;
    }
};
