#include<bits/stdc++.h>;
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> v;
        vector<int> res;
        for(auto i : nums1) v.insert(i);
        
        for(auto i : nums2) {
            if(v.count(i)) {
                res.push_back(i);
                v.erase(i);
            }
        }
        return res;
    }
};