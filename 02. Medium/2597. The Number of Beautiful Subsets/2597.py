class Solution:
    def beautifulSubsets(self, nums: List[int], k: int) -> int:
        n = len(nums)
        freq = [0 for _ in range(2001)]
        def solve(i):
            if i == n:
                return 1
            cnt = 0
            cnt += solve(i + 1)
            if freq[nums[i] - k] == freq[nums[i] + k] and freq[nums[i] - k] == 0:
                freq[nums[i]] += 1
                cnt += solve(i + 1)
                freq[nums[i]] -= 1
            return cnt
        return solve(0) - 1
