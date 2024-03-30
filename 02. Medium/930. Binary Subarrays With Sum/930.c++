#include<bits/stdc++.h>;
using namespace std;

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int cnt = 0, val = 0;
        unordered_map<int, int> mp;
        mp[0] = 1;
        for(auto &i : nums) {
            val += i;
            cnt += mp[val - goal];
            mp[val]++;
        }
        return cnt;
    }
};