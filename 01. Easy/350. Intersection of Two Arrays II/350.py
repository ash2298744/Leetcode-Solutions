class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        d = {}
        for i in nums2:
            if i not in d:
                d[i] = 0
            d[i] += 1
        
        cmn = []
        for i in nums1:
            if d.get(i):
                cmn.append(i)
                d[i] -= 1
        return cmn
        