class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> mp;
        for(char i : s) mp[i]++;

        int ans = 0, odd = 0;
        for(auto [k, v] : mp) {
            odd += (v % 2);
            ans += v - (v % 2);
        }
        return ans + (odd != 0);
    }
};
