class Solution:
    def heightChecker(self, heights: List[int]) -> int:
        cnt = 0
        for i, j in zip(heights, sorted(heights)):
            cnt += (i != j)
        return cnt
        