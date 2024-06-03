class Solution {
public:
    int appendCharacters(string s, string t) {
        int j = 0;
        for(auto &i : s) {
            if(i == t[j]) j++;
            if(j == t.size()) break;
        }
        return t.size() - j;
    }
};
