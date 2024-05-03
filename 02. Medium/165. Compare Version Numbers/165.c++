class Solution {
public:
    void separate(string v, vector<int>& arr) {
        int curr = 0;
        for(auto& c : v) {
            if(c != '.') {
                curr = curr * 10 + (c - '0');
            } else {
                arr.push_back(curr);
                curr = 0;
            }
        }
        arr.push_back(curr);
    }

    int compareVersion(string version1, string version2) {
        vector<int> v1, v2;
        separate(version1, v1);
        separate(version2, v2);

        int n1 = v1.size(), n2 = v2.size();

        if(n1 > n2) {
            while(n2 < n1) {
                v2.push_back(0);
                n2++;
            }
        } 
        else if(n2 > n1) {
            while(n1 < n2) {
                v1.push_back(0);
                n1++;
            }
        }

        for(int i = 0; i < n1; i++) {
            if(v1[i] < v2[i]) return -1;
            if(v1[i] > v2[i]) return 1;
        }
        return 0;
    }
};
