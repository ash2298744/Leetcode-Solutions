class Solution:
    def longestPalindrome(self, s: str) -> int:
        d = {}
        for i in s:
            if i not in d:
                d[i] = 0
            d[i] += 1
        
        ans = odd = 0
        for i in d:
            odd += d[i] % 2
            ans += d[i] - (d[i] % 2)
        return ans + (odd != 0)
