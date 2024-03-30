#include<bits/stdc++.h>;
using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        int n = s.size();
        map<char, int> mp;
        for(auto i : s) mp[i]++;

        vector<vector<char>> v(n + 1);
        for(auto& [i, j] : mp) v[j].push_back(i);

        string res = "";
        for(int i = n; i > 0; i--) {
            for(auto j : v[i]) res.append(i, j);
        }
        return res;
    }
};