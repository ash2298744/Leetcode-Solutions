#include<bits/stdc++.h>;
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int O = 0, K = 0;
        for(int i = 0; i < nums.size(); i++) {
            O += (i + 1);
            K += (nums[i]);
        }
        return O - K;
    }
};