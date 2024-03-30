#include<bits/stdc++.h>;
using namespace std;

class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n = tokens.size(), lo = 0, hi = n - 1, ans = 0, score = 0;
        sort(tokens.begin(), tokens.end());
        while (lo <= hi) {
            if (power >= tokens[lo]) {
                score++;
                power -= tokens[lo++];
            }
            else if (score > 0) {
                score--;
                power += tokens[hi--];
            }
            else lo++;
            ans = max(ans, score);
        }
        return ans;
    }
};
