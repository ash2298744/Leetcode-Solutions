class Solution {
public:
    int numSteps(string s) {
        int n = s.size(), op = 0, ans = 0, carry = 0;
        for(int i = n - 1; i > 0; i--) {
            if((s[i] - '0' + carry) == 1) {
                op++;
                carry = 1;
            }
        }
        return n - 1 + op + carry;
    }
};
