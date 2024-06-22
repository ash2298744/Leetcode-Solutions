class Solution:
    def numberOfSubarrays(self, nums: List[int], k: int) -> int:
        d = defaultdict(int)
        d[0] = 1
        cnt = odd = 0
        for i in nums:
            odd += i % 2
            cnt += d[odd - k]
            d[odd] += 1
        return cnt
