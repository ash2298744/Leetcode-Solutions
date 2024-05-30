class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size(), cnt = 0;
        for(int i = 0; i < n - 1; i++) {
            int XOR = 0;
            for(int j = i; j < n; j++) {
                XOR ^= arr[j];
                if(!XOR) cnt += (j - i);
            }
        }
        return cnt;
    }
};
