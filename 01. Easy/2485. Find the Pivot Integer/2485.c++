class Solution {
public:
    int pivotInteger(int n) {
        int tot = n * (n + 1) / 2, curr = 0;
        for(int i = 1; i <= n; i++) {
            curr = i * (i + 1) / 2;
            if(curr == (tot - curr + i)) return i;
        }
        return -1;
    }
};