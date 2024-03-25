class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();

        for(int i = 0; i < n; i++) {
            int curr = nums[i] - 1, want = i;
            while(curr != want && (nums[curr] - 1) != curr) {
                int temp = nums[curr];
                nums[curr] = nums[want];
                nums[want] = temp;
                curr = nums[i] - 1;
            }
        }

        vector<int> res;
        for(int i = 0; i < n; i++) {
            if(nums[i] != (i + 1)) res.push_back(nums[i]);
        }
        return res;
    }
};
