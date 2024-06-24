class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size(), res = 0;

        vector<int> cnt(n + 1, 0);
        for(int i = 0; i < n - k + 1; i++) {
            if(cnt[i] % 2 == nums[i]) {
                cnt[i]++;
                cnt[i + k]--;
                res++;
            }
            cnt[i + 1] += cnt[i];
        }

        for(int i = n - k + 1; i < n; i++) {
            cnt[i + 1] += cnt[i];
            if(cnt[i] % 2 == nums[i]) return -1;
        }
        return res;
    }
};
