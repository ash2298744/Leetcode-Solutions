class Solution:
    def pivotInteger(self, n: int) -> int:
        tot = n * (n + 1) // 2
        for i in range(1, n + 1):
            curr = i * (i + 1) // 2
            if curr == (tot - curr + i):
                return i
        return -1
        