#include<bits/stdc++.h>;
using namespace std;

class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        vector<long long> pref(1, 0);
        for(auto i : nums){
            pref.push_back(pref.back() + i);
        }
        
        for(int i = nums.size() - 1; i >= 0; i--){
            if(pref[i] > nums[i] && (i + 1) >= 3) return pref[i + 1];
        }
        return -1;
    }
};