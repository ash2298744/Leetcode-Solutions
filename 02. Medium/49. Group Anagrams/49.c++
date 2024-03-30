#include<bits/stdc++.h>;
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        map<string, vector<int>> mp;

        for(int i = 0; i < n; i++) {
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            auto& entry = mp[temp];
            entry.push_back(i);
        }

        vector<vector<string>> res;
        for(auto i : mp) {
            vector<string> t;
            for(auto k : i.second) {
                t.push_back(strs[k]);
            }
            res.push_back(t);
        }
        return res;
    }

};