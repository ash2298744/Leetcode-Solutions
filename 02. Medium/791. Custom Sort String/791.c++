#include<bits/stdc++.h>;
using namespace std;

class Solution {
public:
    string customSortString(string order, string s) {
        for(char i = 'a'; i <= 'z'; i++) {
            if(order.find(i) == string::npos) order += i;
        }
        string res = "";
        for(auto &i : order) {
            for(auto &j : s) {
                if(i == j) res += j;
            }
        }
        return res;
    }
};
