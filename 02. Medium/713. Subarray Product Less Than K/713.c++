class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size(), cnt = 0, j = 0, prod = 1;
        for(int i = 0; i < n; i++) {
            prod *= nums[i];
            while(j <= i && prod >= k) {
                prod /= nums[j++];
            }
            cnt += (i - j + 1);
        }
        return cnt;
    }
};
