class Solution:
    def findLeastNumOfUniqueInts(self, arr: List[int], k: int) -> int:
        d = {}
        for i in arr: 
            if i not in d:
                d[i] = 0
            d[i] += 1
        
        arr = sorted(list(d.items()), key = lambda x : x[1])
        n = len(arr)
    
        i = 0
        while k:
            if k < arr[i][1]:
                return n
            k -= min(k, arr[i][1])
            i += 1
            n -= 1
        return n
