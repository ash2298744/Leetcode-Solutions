class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        if(n < 4) return 0;
        sort(nums.begin(), nums.end());
        int ans = INT_MAX;
        for(int i = 0; i < 4; i++){
            int left = nums[i];
            int right = max(nums[n - (4 - i)], left);
            ans = min(ans, right - left);
        }
        return ans; 
    }
};