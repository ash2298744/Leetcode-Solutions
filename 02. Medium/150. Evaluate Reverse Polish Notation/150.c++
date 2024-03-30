#include<bits/stdc++.h>;
using namespace std;

class Solution {
public:
    int solve(int a, int b, string op) {
        if(op == "+") return a + b;
        if(op == "-") return a - b;
        if(op == "*") return a * b;
        return a / b;
    }

    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(auto i : tokens) {
            if (i == "+" || i == "-" || i == "/" || i == "*") {
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                st.push(solve(a, b, i));
            } else st.push(stoi(i));
        }
        return st.top();
    }
};
