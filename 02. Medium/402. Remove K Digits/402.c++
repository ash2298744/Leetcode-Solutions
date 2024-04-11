class Solution {
public:
    string removeKdigits(string num, int k) {
        deque<char> q;
        for(auto &i : num) {
            while(!q.empty() && k && (q.back() - '0') > (i - '0')) {
                q.pop_back();
                k--;
            }
            q.push_back(i);
        }

        while(!q.empty() && q.front() == '0') {
            q.pop_front();
        }

        while(!q.empty() && k) {
            q.pop_back();
            k--;
        }

        string res;
        while(!q.empty()) {
            res += q.front();
            q.pop_front();
        }

        return res == "" ? "0" : res;
    }
};
