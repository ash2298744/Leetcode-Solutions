class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        map<int, int> mp = {{0, 1}};
        int ans = 0, odd = 0;
        for(int &i : nums) {
            odd += i % 2;
            ans += mp[odd - k];
            mp[odd]++;
        }
        return ans;
    }
};
