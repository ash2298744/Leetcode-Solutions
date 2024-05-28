class Solution:
    def equalSubstring(self, s: str, t: str, maxCost: int) -> int:
        ans = val = j = 0
        for i in range(len(s)):
            val += abs(ord(s[i]) - ord(t[i]))
            while val > maxCost:
                val -= abs(ord(s[j]) - ord(t[j]))
                j += 1
            ans = max(ans, i - j + 1)
        return ans
        