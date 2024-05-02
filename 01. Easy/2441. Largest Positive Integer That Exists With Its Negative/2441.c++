class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_set<int> s;
        int ans = -1;
        for(auto& i : nums) {
            if(s.count(-i)) {
                ans = max(ans, abs(i));
            }
            s.insert(i);
        }
        return ans;
    }   
};
