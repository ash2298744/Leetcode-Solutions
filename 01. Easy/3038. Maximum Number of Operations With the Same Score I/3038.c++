#include<bits/stdc++.h>;
using namespace std;

class Solution {
public:
    int maxOperations(vector<int>& nums) {
        int val = nums[0] + nums[1], cnt = 0, ans = 0, n = nums.size();
        for(int i = 0; i < n; i += 2) {
            if((i + 1) >= n || (nums[i] + nums[i + 1]) != val) break;
            cnt ++;
        }
        return cnt;
    }
};
