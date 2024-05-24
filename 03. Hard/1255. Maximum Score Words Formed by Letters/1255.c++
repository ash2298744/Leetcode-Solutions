class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        int n = words.size();

        vector<int> total(26, 0);
        for(auto &i : letters) total[i - 'a']++;

        vector<vector<int>> dp(n + 1, vector<int>(1 << n, 0));
        for(int i = n; i >= 0; i--) {
            for(int have = 0; have < (1 << n); have++) {
                if(i == n) {
                    vector<int> freq(26, 0);
                    for(int idx = 0; idx < n; idx++) {
                        if((have >> idx) & 1) {
                            for(auto &c : words[idx]) freq[c - 'a']++;
                        }
                    }
                    int cur = 0;
                    for(int a = 0; a < 26; a++) {
                        if(freq[a] > total[a]) {
                            cur = 0;
                            break;
                        }
                        cur += freq[a] * score[a];
                    }
                    dp[i][have] = cur;
                    continue;
                }
                dp[i][have] = max(dp[i][have], max(dp[i + 1][have], dp[i + 1][have | (1 << i)]));
            }
        }
        return dp[0][0];
    }
};
