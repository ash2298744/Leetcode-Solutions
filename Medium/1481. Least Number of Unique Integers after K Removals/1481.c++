#include<bits/stdc++.h>;
using namespace std;

class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        map<int, int> mp;
        for(auto i : arr) mp[i]++;

        vector<int> s;
        for(auto [u, v] : mp) s.push_back(v);
        sort(s.begin(), s.end());

        int n = mp.size();
        for(auto v : s) {
            if(k == 0 || k < v) return n;
            k -= min(k, v);
            n--;
        }
        return n;
    }
};