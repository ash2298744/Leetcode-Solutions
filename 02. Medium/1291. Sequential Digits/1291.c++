#include<bits/stdc++.h>;
using namespace std;

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> res;
        for (int i = 1; i < 9; i++) {
            int num = i;
            while (num % 10 != 9) {
                num = num * 10 + (num % 10 + 1);
                if (num >= low && num <= high) {
                    res.push_back(num);
                }
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};
