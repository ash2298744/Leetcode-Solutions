class Solution {
public:
    bool judgeSquareSum(int c) {
        int n = pow(c, 0.5);
        for(int i = 0; i <= n; i++) {
            int rem = c - pow(i, 2);
            int rootOfRem = pow(rem, 0.5);
            double intRootOfRem = pow(rem, 0.5);
            if(pow(rootOfRem, 2) == pow(intRootOfRem, 2)) return true;
        }
        return false;
    }
};
