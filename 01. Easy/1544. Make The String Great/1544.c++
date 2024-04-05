class Solution {
public:
    string makeGood(string s) {
        stack<char> st;
        for(auto& i : s) {
            if (!st.empty() && abs(i - st.top()) == 32) {
                st.pop();
            } else {
                st.push(i);
            }
        }

        string ans = "";
        while(!st.empty()) {
            char t = st.top();
            st.pop();
            ans = t + ans;
        }
        return ans;
    }
};
