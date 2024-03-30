#include<bits/stdc++.h>;
using namespace std;

class Solution {
public:
    int numSquares(int n) {
        int t = 1;
        while (t * t <= n) {
            t++;
        }

        queue<pair<int, int>> q;
        q.push({n, 0});

        unordered_set<int> s;
        while (!q.empty()) {
            int num = q.front().first;
            int cnt = q.front().second;
            q.pop();

            if (num == 0) {
                return cnt;
            }

            for (int i = 1; i < t; ++i) {
                int temp = i * i;
                if (num >= temp && !s.count(num - temp)) {
                    s.insert(num - temp);
                    q.push({num - temp, cnt + 1});
                }
            }
        }
        return -1;
    }
};
