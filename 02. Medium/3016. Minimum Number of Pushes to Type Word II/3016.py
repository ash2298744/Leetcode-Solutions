class Solution:
    def minimumPushes(self, word: str) -> int:
        freq = [0 for i in range(26)]
        for i in word:
            freq[ord(i) - ord('a')] += 1
        freq.sort(reverse = True)
    
        res, c, t = 0, 1, 8
        for i in freq:
            if t:
                res += c * i
            else:
                t = 8
                c += 1
                res += c * i
            t -= 1
        return res       