class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int cnt = 0, val = 0;
        unordered_map<int,int>mp;
        mp[0] = 1;
        for(auto i : nums){
            val = (val + i) % k;
            if(val < 0) val += k;
            cnt += mp[val]++;
        }
        return cnt;
    }
};
