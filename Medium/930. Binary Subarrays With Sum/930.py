class Solution:
    def numSubarraysWithSum(self, nums: List[int], goal: int) -> int:
        cnt = val = 0
        d = defaultdict(int)
        d[cnt] = 1
        for i in nums:
            val += i
            cnt += d[val - goal]
            d[val] += 1
        return cnt
        