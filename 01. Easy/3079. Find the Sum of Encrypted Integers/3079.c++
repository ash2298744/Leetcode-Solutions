#include<bits/stdc++.h>;
using namespace std;

class Solution {
public:
    int sumOfEncryptedInt(vector<int>& nums) {
        int res = 0;
        for(auto &i : nums) {
            int maxi = 0, num = i, len = 0, newNum = 0;
            
            while(num) {
                maxi = max(maxi, num % 10);
                num /= 10;
                len++;
            }
            
            while(len--) {
                newNum = newNum * 10 + maxi;
            }
            
            res += newNum;
        }
        return res;
    }
};