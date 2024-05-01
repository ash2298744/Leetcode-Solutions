class Solution:
    def reversePrefix(self, word: str, ch: str) -> str:
        seen = 0
        ans = ""
        for c in word:
            ans += c
            if not seen:
                if c == ch:
                    seen = 1
                    ans = ans[::-1]
        return ans
        