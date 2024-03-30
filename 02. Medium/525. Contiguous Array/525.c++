#include<bits/stdc++.h>;
using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int ans = 0, val = 0;
        unordered_map<int, int> mp;
        mp[0] = -1;
        for(int i = 0; i < nums.size(); i++) {
            val += nums[i] ? 1 : -1;
            if(mp.find(val) != mp.end()) ans = max(ans, i - mp[val]);
            else mp[val] = i;
        }
        return ans;
    }
};