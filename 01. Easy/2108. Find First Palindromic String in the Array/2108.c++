#include<bits/stdc++.h>;
using namespace std;

class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for(int i = 0; i < words.size(); i++) {
            string s = words[i];
            int l = 0, r = s.size() - 1;
            while(l < r && s[l] == s[r]) { l++, r--; }
            if(l >= r) return s;
        }
        return "";
    }
};