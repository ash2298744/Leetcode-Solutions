class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<string> ans;
        for(char ch = 'a'; ch <= 'z'; ch++) {
            int mi = 2024;
            for(int i = 0; i < words.size(); i++) {
                int cnt = 0;
                for(char j : words[i]) {
                    if(j == ch) cnt++;
                }
                mi = min(mi, cnt);
            }
            for(int x = 0; x < mi; x++) {
                string curr;
                curr = ch;
                ans.push_back(curr);
            }
        }
        return ans;
    }
};
