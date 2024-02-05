#include<bits/stdc++.h>;
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        vector<vector<int>> idx(26, vector<int> (2, -1));
        for(int i = 0; i < s.size(); i++) {
            if (idx[s[i] - 'a'][0] == -1) idx[s[i] - 'a'][0] = i;
            idx[s[i] - 'a'][1] = max(idx[s[i] - 'a'][1], i);
        }

        int res = INT_MAX;
        for(int i = 0; i < 26; i++) {
            if(idx[i][0] == idx[i][1] && idx[i][0] != -1) res = min(res, idx[i][0]);
        }
        return res == INT_MAX ? -1 : res;
    }
};