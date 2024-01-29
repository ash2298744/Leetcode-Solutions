#include<bits/stdc++.h>;
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int n = nums.size(), temp;

        int i = 0;
        while (i < n - 3) {
            int j = i + 1;

            while (j < n - 2) {
                int ii = j + 1, jj = n - 1; 
                long long val = nums[i] + nums[j];

                while (ii < jj) {
                    if((val + nums[ii] + nums[jj]) == target) {
                        ans.push_back({nums[i], nums[j], nums[ii], nums[jj]});

                        temp = nums[ii];
                        while (ii < jj && nums[ii++] == temp);

                        temp = nums[jj];
                        while (ii < jj && nums[jj--] == temp);
                    } 
                    else if ((val + nums[ii] + nums[jj]) < target) ii++;
                    else jj--;
                }

                temp = nums[j];
                while (j < n - 2 && nums[j++] == temp);
            }

            temp = nums[i];
            while (i < n - 3 && nums[i++] == temp);
        }
        return ans;
    }
};
