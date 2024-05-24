class Solution:
    def maxScoreWords(self, words: List[str], letters: List[str], score: List[int]) -> int:
        n = len(words)

        tot = [0 for _ in range(26)]
        for i in letters:
            tot[ord(i) - 97] += 1

        dp = [[0 for _ in range(1 << n)] for _ in range(n + 1)]
        for i in range(n, -1, -1):
            for have in range(1 << n):
                if i == n:
                    freq = [0 for _ in range(26)]
                    for idx in range(n):
                        if (have >> idx) & 1:
                            for j in words[idx]:
                                freq[ord(j) - 97] += 1
                    cur = 0
                    for a in range(26):
                        if freq[a] > tot[a]:
                            cur = 0
                            break
                        cur += freq[a] * score[a]  
                    dp[n][have] = cur
                    continue
                dp[i][have] = max(dp[i][have], dp[i + 1][have], dp[i + 1][have | (1 << i)])
        return dp[0][0]
