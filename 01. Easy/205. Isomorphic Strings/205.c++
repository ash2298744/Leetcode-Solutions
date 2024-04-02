class Solution {
public:
    bool isIsomorphic(string s, string t) {
        set<pair<char, char>> mapped;
        set<char> ss, tt;
        for(int i = 0; i < s.size(); i++) {
            mapped.insert({s[i], t[i]});
            ss.insert(s[i]);
            tt.insert(t[i]);
        }
        return mapped.size() == ss.size() && ss.size() == tt.size();
    }
};
