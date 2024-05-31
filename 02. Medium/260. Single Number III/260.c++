class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long xorSum = 0;
        for(auto &i : nums) xorSum ^= i;

        int ele1 = 0, ele2 = 0, bit = xorSum & -xorSum;
        for(auto &i : nums) {
            if(i & bit) ele1 ^=i ;
            else ele2 ^= i;
        }
        return {ele1, ele2};
    }
};
