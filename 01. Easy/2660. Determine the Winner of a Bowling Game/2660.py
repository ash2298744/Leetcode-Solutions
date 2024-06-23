class Solution:
    def isWinner(self, player1: List[int], player2: List[int]) -> int:
        val1, val2, c1, c2 = 0, 0, 0, 0

        for i, j in zip(player1, player2):
            if c1 >= 1:
                val1 += 2 * i
                c1 -= 1
            else:
                val1 += i

            if c2 >= 1:
                val2 += 2 * j
                c2 -= 1
            else:
                val2 += j

            if i == 10:
                c1 = 2
            if j == 10:
                c2 = 2

        if val1 > val2:
            return 1
        elif val1 < val2:
            return 2
        return 0
