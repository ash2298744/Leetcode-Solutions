class Solution:
    def subarraysWithKDistinct(self, nums: List[int], k: int) -> int:
        def solve(kk):
            d = {}
            cnt = j = 0
            for i in range(len(nums)):
                if nums[i] not in d:
                    d[nums[i]] = 0
                d[nums[i]] += 1

                while j <= i and len(d.keys()) > kk:
                    d[nums[j]] -= 1
                    if d[nums[j]] == 0:
                        del d[nums[j]]
                    j += 1
                
                cnt += (i - j + 1)
            return cnt
            
        return solve(k) - solve(k - 1)
