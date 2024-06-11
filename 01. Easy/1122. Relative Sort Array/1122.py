class Solution:
    def relativeSortArray(self, arr1: List[int], arr2: List[int]) -> List[int]:
        d = defaultdict(int)
        for i in arr1:
            d[i] += 1

        new = []
        for i in arr2:
            new += [i for _ in range(d[i])]
            del d[i]
        
        tmp = []
        for i in d:
            tmp += [i for _ in range(d[i])]
        return new + sorted(tmp)
        