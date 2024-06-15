class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        map<int, int> mp;
        for(int &i : deck) mp[i]++;

        int g = 0;
        for(auto [k, v] : mp) {
            g = __gcd(g, v);
        }
        return g > 1;
    }
};
