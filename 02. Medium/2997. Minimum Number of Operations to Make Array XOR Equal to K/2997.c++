class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int x = 0;
        for(auto i : nums) x ^= i;
        int cnt = 0;
        for(int i = 0; i < 32; i++){
            cnt += !((x & (1 << i)) ^ (k & (1 << i)));
        }
        return 32 - cnt;
    }
};
