class Solution:
    def maximumOddBinaryNumber(self, s: str) -> str:
        cnt = 0
        for i in s:
            cnt += (i == '1')

        ans = ""
        for i in range(len(s) - 1):
            if cnt > 1:
                ans += "1"
            else:
                ans += "0"
            cnt -= 1
        return ans + "1"
