#include<bits/stdc++.h>;
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size() / 2;
        unordered_map<int, int> m;
        int ans = 0;
        for (auto i : nums) {
            if (++m[i] > n) return i; 
        }
        return -1;
    }
};