class Solution:
    def maxDepth(self, s: str) -> int:
        mx = cnt = 0
        for i in s:
            if i == "(": cnt += 1
            elif i == ")": cnt -= 1
            mx = max(mx, cnt)
        return mx

