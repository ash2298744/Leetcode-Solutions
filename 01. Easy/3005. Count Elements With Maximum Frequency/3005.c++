#include<bits/stdc++.h>;
using namespace std;

class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> mp;
        int maxi = 0;
        for(auto i : nums) maxi = max(maxi, ++mp[i]);
        
        int res = 0;
        for(auto i : mp){
            if(i.second == maxi) res += maxi;
        }
        return res;
    }
};