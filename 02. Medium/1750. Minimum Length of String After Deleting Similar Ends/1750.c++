#include<bits/stdc++.h>;
using namespace std;

class Solution {
public:
    int minimumLength(string s) {
        int lo = 0, hi = s.size() - 1;
        while (lo < hi) {
            char temp = s[lo];
            if (s[lo] != s[hi]) break;
            else {
                while (lo < hi && s[lo] == temp) lo++;
                if(lo == hi) return 0;
                while (lo < hi && s[hi] == temp) hi--;
            }
        }
        return lo < hi ? hi - lo + 1 : 1;
    }
};
