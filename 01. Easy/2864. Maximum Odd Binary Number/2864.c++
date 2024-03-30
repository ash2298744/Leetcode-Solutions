#include<bits/stdc++.h>;
using namespace std;

class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int cnt = 0;
        for (auto i : s)
            cnt += (i == '1');

        string res = "";
        for (int i = 0; i < s.size() - 1; i++) {
            if (--cnt > 0)
                res += '1';
            else
                res += '0';
        }
        return res + '1';
    }
};
