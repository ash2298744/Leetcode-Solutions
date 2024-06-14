class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int res = 0, mx = 0;
        for(int i = 1; i < nums.size(); i++) {
            mx = max(mx, nums[i - 1]);
            if(nums[i] <= mx) {
                mx++;
                res += abs(mx - nums[i]);
                nums[i] = mx;
            }
        }
        return res;
    }
};
