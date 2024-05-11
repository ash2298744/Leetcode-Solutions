class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n = wage.size();

        vector<pair<double, int>> arr;
        for(int i = 0; i < n; i++) {
            arr.push_back({1.0 * wage[i] / quality[i], quality[i]});
        }
        sort(arr.begin(), arr.end());

        double ans = DBL_MAX, sum = 0;
        priority_queue<int> pq;
        for(int i = 0; i < n; i++) {
            sum += arr[i].second;
            pq.push(arr[i].second);
            if(pq.size() > k) {
                sum -= pq.top();
                pq.pop();
            }
            if(pq.size() == k) {
                ans = min(ans, sum * arr[i].first);
            }
        } 
        return ans;
    }
};
