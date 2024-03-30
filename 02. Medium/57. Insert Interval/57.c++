#include<bits/stdc++.h>;
using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;
        vector<int> prev = intervals[0];
        intervals.erase(intervals.begin());
        while(!intervals.empty()) {
            int a = intervals[0][0], b = intervals[0][1];
            if(a >= prev[0] && a <= prev[1]) {
                prev[0] = min(prev[0], a);
                prev[1] = max(b, prev[1]);
            } else {
                ans.push_back(prev);
                prev = intervals[0];
            }
            intervals.erase(intervals.begin());
        }
        ans.push_back(prev);
        return ans;
    }
};
