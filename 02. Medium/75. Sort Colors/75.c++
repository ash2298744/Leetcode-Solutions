class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i = 0, l = 0, r = nums.size() - 1;
        while(i >= l and i <= r) {
            if(nums[i] == 0) {
                swap(nums[i], nums[l]);
                l++;
                i++;
            } else if(nums[i] == 2) {
                swap(nums[i], nums[r]);
                r--;
            } else i++;
        }
    }
};
