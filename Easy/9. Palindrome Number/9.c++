#include<bits/stdc++.h>;
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        } else {
            long long n = 0, p = x;
            while (x) {
                n = n * 10 + x % 10;
                x = x / 10;
            }
            return n == p;
        }
    }
};