class Solution {
public:
    void solve(int i, string s, vector<string>& ans, vector<string>& arr, unordered_set<string> v) {
        if(i == s.size()) {
            string x = "";
            int currLen = arr.size();
            for(int ii = 0; ii < currLen; ii++) {
                if(ii == currLen - 1) x += arr[ii];
                 else x += arr[ii] + " ";
            }
            ans.push_back(x);
            return;
        }

        string currS;
        for(int j = i; j < s.size(); j++) {
            currS += s[j];
            if(v.count(currS)) {
                arr.push_back(currS);
                solve(j + 1, s, ans, arr, v);
                arr.pop_back();
            }
        }
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        unordered_set<string> v(wordDict.begin(), wordDict.end());
        vector<string> ans, arr;
        solve(0, s, ans, arr, v);
        return ans;
    }
};
