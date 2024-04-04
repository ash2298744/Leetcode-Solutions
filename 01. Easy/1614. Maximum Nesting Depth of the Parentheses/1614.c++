class Solution {
public:
    int maxDepth(string s) {
        int cnt = 0, mx = 0;
        for(auto &i : s) {
            cnt += (i == '(');
            mx = max(mx, cnt);
            cnt -= (i == ')');
        }
        return mx;
    }
};
