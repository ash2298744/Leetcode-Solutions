class Solution {
public:
    bool check(int idx, int have, vector<int>& nums, int k, int n) {
        for(int i = 0; i < n; i++)
            if((have >> i) & 1 && abs(nums[idx] - nums[i]) == k) return false;
        return true;
    }

    int solve(int i, int have, vector<vector<int>>& dp, vector<int>& nums, int k, int n) {
        if(i == n) return 1;
        if(dp[i][have] != -1) return dp[i][have];
        int cnt = 0;
        cnt += solve(i + 1, have, dp, nums, k, n);
        if(check(i, have, nums, k, n))  cnt += solve(i + 1, have | (1 << i), dp, nums, k, n);
        return dp[i][have] = cnt;
    }

    int beautifulSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(1 << n, -1));
        return solve(0, 0, dp, nums, k, n) - 1;
    }
};
