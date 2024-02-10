class Solution:
    def countKeyChanges(self, s: str) -> int:
        s = s.lower()
        cnt = 0
        for i in range(1, len(s)):
            cnt += (s[i] != s[i - 1]) 
        return cnt