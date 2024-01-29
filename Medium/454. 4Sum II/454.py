# from collections import defaultdict

class Solution:
    def fourSumCount(self, nums1: List[int], nums2: List[int], nums3: List[int], nums4: List[int]) -> int:
        n = len(nums1)
        d1, d2 = defaultdict(int), defaultdict(int)

        for i in range(n):
            for j in range(n):
                d1[nums1[i] + nums2[j]] += 1

        for i in range(n):
            for j in range(n):
                d2[nums3[i] + nums4[j]] += 1

        cnt = 0
        for i in d1:
            cnt += d1[i] * d2[-i]
        return cnt