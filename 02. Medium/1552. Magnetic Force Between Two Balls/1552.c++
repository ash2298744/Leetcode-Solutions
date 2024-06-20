class Solution {
public:
    bool canPlace(int force, int m, vector<int> position) {
        int cnt = 1, prev = position[0];
        for(int &i : position) {
            if((i - prev) > force) {
                prev = i;
                cnt++;
            }
        }
        return cnt < m;
    }

    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int lo = 1, hi = 1e9 + 1;
        while(lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if(canPlace(mid, m, position)) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return lo;
    }
};
