class Solution:
    def commonChars(self, words: List[str]) -> List[str]:
        ans = []
        for ch in set(words[0]):
            mi = 2024
            for i in words:
                cnt = 0
                for j in i:
                    if j == ch:
                        cnt += 1
                mi = min(cnt, mi)
            ans += [ch for _ in range(mi)]
        return ans
