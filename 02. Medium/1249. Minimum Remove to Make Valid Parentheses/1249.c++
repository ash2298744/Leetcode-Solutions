class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n = s.size();
        stack<int> st;
        for(int i = 0; i < n; i++) {
            if(s[i] == '(') st.push(i);
            else if(s[i] == ')') {
                if(!st.empty() && s[st.top()] == '(') st.pop();
                else s[i] ='#';
            }
        }
        while(!st.empty()) {
            s[st.top()] = '#';
            st.pop();
        }

        string res;
        for(auto &i : s) {
            if(i != '#') res += i;
        }
        return res;
    }
};
