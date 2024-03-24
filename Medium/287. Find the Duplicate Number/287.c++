class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0], fast = nums[0];
        while(2024) {
            slow = nums[slow];
            fast = nums[nums[fast]];
            if(slow == fast) break;
        }

        int curr = nums[0];
        while(curr != slow) {
            slow = nums[slow];
            curr = nums[curr];
        }
        return curr;
    }
};
