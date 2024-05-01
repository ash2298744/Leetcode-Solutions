class Solution {
public:
    string reversePrefix(string word, char ch) {
        int seen = 0;
        string res;
        for(auto& c : word) {
            res += c;
            if(!seen) {
                if(ch == c) {
                    seen = 1;
                    reverse(res.begin(), res.end());
                }
            }
        }
        return res;
    }
};
