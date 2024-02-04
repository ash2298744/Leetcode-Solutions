#include<bits/stdc++.h>;
using namespace std;

class Solution {
public:
    int returnToBoundaryCount(vector<int>& nums) {
        int sum = 0, cnt = 0;
        for(auto i : nums) {
            sum += i;
            cnt += (sum == 0);
        }
        return cnt;
    }
};