class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        s = []
        for i in strs:
            s.append("".join(sorted(i)))

        d = {}
        for i in range(len(s)):
            if s[i] not in d:
                d[s[i]] = []
            d[s[i]].append(strs[i])

        res = []
        for i in d:
            res.append(d[i])
        return res