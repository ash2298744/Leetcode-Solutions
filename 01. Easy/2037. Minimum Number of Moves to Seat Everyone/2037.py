class Solution:
    def minMovesToSeat(self, seats: List[int], students: List[int]) -> int:
        moves = 0
        for i, j in zip(sorted(seats), sorted(students)):
            moves += abs(i - j)
        return moves
        