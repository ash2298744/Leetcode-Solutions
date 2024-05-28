class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int ans = 0, val = 0, j = 0;
        for(int i = 0; i < s.size(); i++) {
            val += abs((s[i] - 'a') - (t[i] - 'a'));
            while(val > maxCost) {
                val -= abs((s[j] - 'a') - (t[j] - 'a'));
                j++;
            }
            ans = max(ans, i - j + 1);
        }
        return ans;
    }
};
