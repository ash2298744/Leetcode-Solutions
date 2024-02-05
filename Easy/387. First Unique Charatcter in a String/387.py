class Solution:
    def firstUniqChar(self, s: str) -> int:
        idx = [[-1, -1] for i in range(26)]
        for i in range(len(s)):
            if idx[ord(s[i]) - ord('a')][0] == -1:
                idx[ord(s[i]) - ord('a')][0] = i
            idx[ord(s[i]) - ord('a')][1] = max(idx[ord(s[i]) - ord('a')][1], i)

        res = inf
        for i in idx:
            if i[0] != -1 and i[0] == i[1]:
                res = min(res, i[1])
        return res if res != inf else -1