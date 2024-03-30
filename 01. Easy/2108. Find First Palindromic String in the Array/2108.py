class Solution:
    def firstPalindrome(self, words: List[str]) -> str:
        for i in words:
            s = i
            l, r = 0, len(s) - 1
            while l < r and s[l] == s[r]:
                l, r = l + 1, r - 1
            if l >= r:
                return s
        return ""