#include<bits/stdc++.h>;
using namespace std;

class Solution {
public:
    bool isPrime(int num) {
        if(num <= 10) return false;
        for(int i = 2; i * i <= num; i++) {
            if(num % i == 0) return false;
        }
        return true;
    }

    int mostFrequentPrime(vector<vector<int>>& mat) {
        unordered_map<int, int> mp;
        int m = mat.size(), n = mat[0].size(), mx = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                for (int dx = -1; dx <= 1; dx++) {
                    for(int dy = -1; dy <= 1; dy++) {
                        long long ii = i, jj = j, num = 0;
                        while(ii >= 0 && ii < m && jj >= 0 && jj < n) {
                            num = num * 10 + mat[ii][jj];
                            if(isPrime(num)) mx = max(mx, ++mp[num]);
                            if(dx == 0 && dy == 0) break;
                            ii += dx;
                            jj += dy;
                        }
                    }
                }
            }
        }
        int res = -1;
        for(auto [k, v] : mp) {
            if(v == mx) res = max(res, k);
        }
        return res;
    }
};