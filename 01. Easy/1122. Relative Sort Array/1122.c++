class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, int> mp;
        for(int i : arr1) mp[i]++;

        vector<int> cur, tmp;
        for(int i : arr2) {
            while(mp[i]--) {
                cur.push_back(i);
            }
        }

        for(auto [k, v] : mp) {
            while(v-- > 0) {
                tmp.push_back(k);
            }
        }
        sort(tmp.begin(), tmp.end());
        
        for(int i : tmp) cur.push_back(i);
        return cur;
    }
};
