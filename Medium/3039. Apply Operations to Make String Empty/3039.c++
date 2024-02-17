#include<bits/stdc++.h>;
using namespace std;

class Solution {
public:
    string lastNonEmptyString(string s) {
        int mx = 0, n = s.size();
        vector<int> freq(26, 0);
        for(auto i : s) mx = max(mx, ++freq[i - 'a']);

        string ans = "";
        for(int i = n - 1; i >= 0; i--) {
            if(freq[s[i] - 'a'] >= mx) {
                ans = s[i] + ans;
                freq[s[i] - 'a'] = 0;
            } 
        }
        return ans;
    }
};
