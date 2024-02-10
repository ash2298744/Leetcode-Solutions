#include <iostream>
using namespace std;

class Solution {
public:
    int countKeyChanges(string s) {
        int cnt = 0, n = s.size();
        for(int i = 1; i < n; i++) {
            cnt += (tolower(s[i]) != tolower(s[i - 1]));
        }
        return cnt;
    }
};