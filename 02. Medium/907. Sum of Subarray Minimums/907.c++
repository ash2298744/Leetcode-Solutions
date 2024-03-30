#include<bits/stdc++.h>;
using namespace std;

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size(), MOD = 1e9 + 7;
        vector<int> nse(n, n), pge(n, -1);
        stack<int> s1, s2;

        for(int i = n - 1; i >= 0; i--){
            while(!s1.empty() && arr[i] <= arr[s1.top()])
                s1.pop();
            
            if(!s1.empty()) 
                nse[i] = s1.top();

            s1.push(i);
        }

        for(int i = 0; i < n; i++){
            while(!s2.empty() && arr[i] < arr[s2.top()])
                s2.pop();

            if(!s2.empty()) 
                pge[i] = s2.top();
                
            s2.push(i);
        }

        int res = 0;
        for(int i = 0; i < n; i++){
            int l = i - pge[i];
            int r = nse[i] - i;
            res = (res + 1LL * l * r * arr[i]) % MOD;
        }
        return res;
    }
};