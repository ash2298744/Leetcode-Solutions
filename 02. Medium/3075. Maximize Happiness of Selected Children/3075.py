class Solution:
    def maximumHappinessSum(self, happiness: List[int], k: int) -> int:
        n = len(happiness)
        happiness.sort(reverse = True)
        
        res = 0
        for i in range(min(n, k)):
            res += max(0, happiness[i] - i)
        return res
