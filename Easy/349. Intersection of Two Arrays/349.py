class Solution:
    def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:
        v = set()
        for i in nums1:
            v.add(i)

        res = []
        for i in nums2:
            if i in v:
                res.append(i)
                v.remove(i)
        return res
        