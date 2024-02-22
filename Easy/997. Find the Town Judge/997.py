class Solution:
    def findJudge(self, n: int, trust: List[List[int]]) -> int:
        a, b = {}, {}
        for i in trust:
            a[i[0]] = a.get(i[0], 0) + 1
            b[i[1]] = b.get(i[1], 0) + 1

        for i in range(1, n + 1):
            if len(a.keys()) == n - 1 and b.get(i, 0) == n - 1 and a.get(i, 0) == 0:
                return i
        return -1      