class Solution:
    def minimumLength(self, s: str) -> int:
        lo, hi = 0, len(s) - 1
        while lo < hi:
            temp = s[lo]
            if s[hi] != s[lo]:
                break
            else:
                while lo < hi and s[lo] == temp: lo += 1
                if lo == hi: return 0
                while lo < hi and s[hi] == temp: hi -= 1
        return hi - lo + 1 if lo < hi else 1
