#include<bits/stdc++.h>;
using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int i = 0, j = 0, n = nums.size();
        if(n == 1) return {to_string(nums[0])};
        vector<string> res;
        while (j < n - 1) {
            while (j < n - 1 && nums[j] == nums[j + 1] - 1) j++;
            if(i != j) res.push_back({to_string(nums[i]) + "->" + to_string(nums[j])});
            else res.push_back({to_string(nums[i])});
            i = ++j;
            if (j == n - 1) res.push_back({to_string(nums[i])});
        }
        return res;
    }
};
