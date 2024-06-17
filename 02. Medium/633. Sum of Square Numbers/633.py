class Solution:
    def judgeSquareSum(self, c: int) -> bool:
        n = int(c ** 0.5)
        for i in range(n + 1):
            rem = c - (i ** 2)
            if int(rem ** 0.5) ** 2 == (rem ** 0.5) ** 2:
                return True
        return False
