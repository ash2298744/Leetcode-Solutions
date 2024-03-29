class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long n = nums.size(), maxi = 0, maxiFreq = 0, maxiCnt = 0, j = 0;
        for(int i = 0; i < n; i++) maxi = max(maxi, (long long)nums[i]);
        for(int i = 0; i < n; i++) {
            maxiFreq += (nums[i] == maxi);
            while(j <= i && maxiFreq == k) {
                maxiFreq -= (nums[j++] == maxi);
            }
            maxiCnt += (i - j + 1);
        }
        return 1LL * (n * (n + 1) / 2) - maxiCnt;
    }
};
