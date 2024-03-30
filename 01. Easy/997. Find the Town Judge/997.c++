#include<bits/stdc++.h>;
using namespace std;

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        unordered_map<int, int> mp1, mp2;
        for(auto i : trust) {
            mp1[i[0]]++;
            mp2[i[1]]++;
        }

        if (mp1.size() != n - 1) return -1;
        
        for(int i = 1; i <= n; i++) {
            if(mp1[i] == 0 and mp2[i] == n - 1) return i;
        }
        return -1;
    }
};