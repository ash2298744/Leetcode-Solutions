class Solution {
public:
    int solve(vector<int> nums, int kk) {
        unordered_map<int, int>mp;
        int cnt = 0, j = 0;
        for(int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
            while(j <= i && mp.size() > kk) {
                --mp[nums[j]];
                if(mp[nums[j]] == 0) {
                    mp.erase(nums[j]);
                }
                j++;
            }
            cnt += (i - j + 1);
        }
        return cnt;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return solve(nums, k) - solve(nums, k - 1);
    }
};
