class Solution:
    def numWaterBottles(self, numBottles: int, numExchange: int) -> int:
        res = empty = 0
        while numBottles:
            numBottles -= 1
            empty += 1
            res += 1
            if empty == numExchange:
                numBottles += 1
                empty = 0
        return res
