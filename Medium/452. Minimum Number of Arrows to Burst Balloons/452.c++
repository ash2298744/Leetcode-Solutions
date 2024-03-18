#include<bits/stdc++.h>;
using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](const auto& a, const auto& b) {
            return a[1] < b[1];
        });
        int cnt = 1, prev = points[0][1];
        for(int i = 1; i < points.size(); i++) {
            if(prev < points[i][0] | prev > points[i][1]) {
                cnt++;
                prev = points[i][1];
            }
        }
        return cnt;
    }
};
