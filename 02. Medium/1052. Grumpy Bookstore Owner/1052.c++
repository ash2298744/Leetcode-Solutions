class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
    
        int tot = 0;
        for(int i = 0; i < n; i++) {
            if(!grumpy[i]) tot += customers[i];
        }

        int ans = 0, j = 0;
        for(int i = 0; i < n; i++) {
            if(grumpy[i]) tot += customers[i];

            if ((i - j + 1) > minutes) {
                if(grumpy[j]) tot -= customers[j];
                j++;
            }

            ans = max(ans, tot);
        }
        return ans;
    }
};
