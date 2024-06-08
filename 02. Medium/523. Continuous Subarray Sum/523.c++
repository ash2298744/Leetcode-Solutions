class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> dp;
        int sum = 0;
        dp[sum] = -1;
        for(int i = 0; i < nums.size(); i++) {
            sum = (sum + nums[i]) % k;
            if(dp.find(sum) != dp.end()) {
                if((i - dp[sum]) >= 2) return true;
            } else dp[sum] = i;
        }
        return false;
    }
};
