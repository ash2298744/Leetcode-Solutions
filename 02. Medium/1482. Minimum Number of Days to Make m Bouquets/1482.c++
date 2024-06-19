class Solution {
public:
    bool canMakeWithDay(int day, int m, int k, vector<int> bloomDay) {
        int currK = 0, currM = 0;
        for(int &i : bloomDay) {
            if(i <= day) {
                if(++currK == k) {
                    currM++;
                    currK = 0;
                }   
            } else currK = 0;
        }
        return currM >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int lo = *min_element(bloomDay.begin(), bloomDay.end()), hi = *max_element(bloomDay.begin(), bloomDay.end());
        int mx = hi;
        while(lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if(canMakeWithDay(mid, m, k, bloomDay)) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return lo <= mx ? lo : -1;
    }
};
