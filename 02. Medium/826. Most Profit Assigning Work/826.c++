class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = profit.size();

        vector<pair<int, int>> arr;
        for(int i = 0; i < n; i++) {
            arr.push_back({difficulty[i], profit[i]});
        }
        sort(arr.begin(), arr.end(), [](const pair<int, int>a, const pair<int, int>b){ return a.first < b.first; });

        vector<int> maxProfit;
        int mx = 0;
        for(int i = 0; i < n; i++) {
            mx = max(mx, arr[i].second);
            maxProfit.push_back(mx);
        }

        int totalProfit = 0;
        for(int &i : worker) {
            int lo = 0, hi = n - 1;
            while(lo <= hi) {
                int mid = lo + (hi - lo) / 2;
                if(arr[mid].first <= i) {
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                }
            }
            if(hi >= 0) totalProfit += maxProfit[hi];
        }
        return totalProfit;
    }
};
