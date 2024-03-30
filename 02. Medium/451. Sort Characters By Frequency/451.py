class Solution:
    def frequencySort(self, s: str) -> str:
        d = {}
        for i in s:
            if i not in d:
                d[i] = 0
            d[i] += 1

        arr = []
        for i in d:
            arr.append([i, d[i]])

        arr = sorted(arr, key = lambda x : x[1], reverse = True)

        res = ""
        for i in arr:
            res += i[0] * i[1]
        return res