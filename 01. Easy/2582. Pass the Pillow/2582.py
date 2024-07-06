class Solution:
    def passThePillow(self, n: int, time: int) -> int:
        curr = turn = 1
        while time:
            if turn:
                while time and curr < n:
                    curr += 1
                    time -= 1
            else:
                while time and curr > 1:
                    curr -= 1
                    time -= 1
            turn ^= 1
        return curr
    