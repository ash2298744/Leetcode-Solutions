class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();
        priority_queue<pair<double, pair<int, int>>, vector<pair<double, pair<int, int>>>, greater<>> pq;
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                pq.push({(double)arr[i] / arr[j], {arr[i], arr[j]}});
            }
        }
        while(!pq.empty() && --k) pq.pop();
        return {pq.top().second.first, pq.top().second.second};
    }
};
