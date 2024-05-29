class Solution:
    def numSteps(self, s: str) -> int:
        carry = op = 0
        for i in s[1:][::-1]:
            if int(i) + carry == 1:
                op += 1
                carry = 1
        return len(s) - 1 + op + carry
