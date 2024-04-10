class Solution:
    def deckRevealedIncreasing(self, deck: List[int]) -> List[int]:
        deck.sort()
        ans = [deck.pop()]
        while deck:
            temp = ans.pop()
            ans = [deck.pop()] + [temp] + ans
        return ans
