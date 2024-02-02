class Solution:
    def sequentialDigits(self, low: int, high: int) -> List[int]:
        dig = []
        for j in range(1, 9):
            for _ in range(8):
                if j % 10 == 9:
                    break
                j = j * 10 + (j % 10 + 1)
                if j >= low and j <= high:
                    dig.append(j)
        return sorted(dig)
