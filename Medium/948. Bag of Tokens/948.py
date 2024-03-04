class Solution:
    def bagOfTokensScore(self, tokens: List[int], power: int) -> int:
        tokens.sort()
        n = len(tokens)
        lo, hi = 0, n - 1
        ans = score = 0
        while lo <= hi:
            if power >= tokens[lo]:
                score += 1
                power -= tokens[lo]
                lo += 1
            elif score >= 1:
                score -= 1
                power += tokens[hi]
                hi -= 1
            else:
                lo += 1
            ans = max(ans, score)
        return ans
