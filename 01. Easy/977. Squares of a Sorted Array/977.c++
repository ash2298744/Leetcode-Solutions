#include<bits/stdc++.h>;
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size(), idx = n - 1, l = 0, r = n - 1;
        vector<int> res(n);
        while (l <= r) {
            if(nums[l] * nums[l] > nums[r] * nums[r]) {
                res[idx--] = nums[l] * nums[l++];
            } else {
                res[idx--] = nums[r] * nums[r--];
            }
        }
        return res;
    }
};
