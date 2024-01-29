#include<bits/stdc++.h>;
using namespace std;

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> mp1, mp2;
        int n = nums1.size(), cnt = 0;

        for(auto i : nums1)
            for(auto j : nums2)
                mp1[i + j]++;

        for(auto i : nums3)
            for(auto j : nums4)
                mp2[i + j]++;

        for(auto i : mp1)
            cnt += mp1[i.first] * mp2[-i.first];

        return cnt;
    }
};
