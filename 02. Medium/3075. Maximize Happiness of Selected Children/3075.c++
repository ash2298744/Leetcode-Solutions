class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        int n = happiness.size();
        sort(happiness.begin(), happiness.end(), greater<int>());

        long long res = 0;
        for(int i = 0; i < min(n, k); i++) {
            res += max(0, happiness[i] - i);
        }
        return res;
    }
};
