#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumPushes(string word) {
        vector<int> freq(26, 0);
        for(auto i : word) freq[i - 'a']++;
        sort(freq.begin(), freq.end(), greater<int>());
        
        int res = 0, t = 8, c = 1;
        for(auto i : freq) {
            if(t--) {
                res += c * i;
            }
            else {
                t = 7;
                res += ++c * i;
            }
        }
        return res;
    }
};
