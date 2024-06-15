class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        map<int, int> mp;
        for(int &i : deck) mp[i]++;

        int g = 0;
        for(auto [k, v] : mp) {
            g = __gcd(g, v);
        }

        if(g == 1) return false;

        for(auto [k, v] : mp) {
            if(v % g) return false;
        }
        return true;
    }
};
