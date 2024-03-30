class Solution:
    def maxOperations(self, nums: List[int]) -> int:
        n, cnt = len(nums), 0
        for i in range(0, n, 2):
            if (i + 1) >= n or (nums[i] + nums[i + 1]) != (nums[0] + nums[1]):
                break
            cnt += 1
        return cnt
        