class Solution:
    def isNStraightHand(self, hand: List[int], groupSize: int) -> bool:
        hand.sort()

        d = defaultdict(int)
        for i in hand:
            d[i] += 1
        
        for i in hand:
            if d[i]:
                curr = d[i]
                for j in range(groupSize):
                    if d[i + j] < curr:
                        return False
                    d[i + j] -= curr
        return True
