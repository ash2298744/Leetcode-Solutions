class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> List[str]:
        n = len(s)
        wordDict = set(wordDict)
        arr = []
        ans = []
        def solve(i):
            if i == n:
                ans.append(" ".join(arr))
                return
            for j in range(i, n):
                if s[i : j + 1] in wordDict:
                    arr.append(s[i : j + 1])
                    solve(j + 1)
                    arr.pop()
        solve(0)
        return ans
