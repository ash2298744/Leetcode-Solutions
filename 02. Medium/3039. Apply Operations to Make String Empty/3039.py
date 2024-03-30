class Solution:
    def lastNonEmptyString(self, s: str) -> str:
        freq = [0 for i in range(26)]
        mx = 0
        for i in s:
            freq[ord(i) - ord('a')] += 1
            mx = max(freq[ord(i) - ord('a')], mx)
            
        ans = ""
        for i in s[::-1]:
            if freq[ord(i) - ord('a')] >= mx:
                ans = i + ans
                freq[ord(i) - ord('a')] = 0
        return ans
