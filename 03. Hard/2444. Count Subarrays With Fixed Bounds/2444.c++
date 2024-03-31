class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long cnt = 0, minIdx = -1, maxIdx = -1, noneIdx = -1;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] < minK || nums[i] > maxK) noneIdx = i;
            if(nums[i] == minK) minIdx = i;
            if(nums[i] == maxK) maxIdx = i;
            cnt += max(0 * 1LL, min(minIdx, maxIdx) - noneIdx);
        }
        return cnt;
    }
};
