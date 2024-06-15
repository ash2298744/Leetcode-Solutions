class Solution:
    def hasGroupsSizeX(self, deck: List[int]) -> bool:
        d = {}
        for i in deck:
            if i not in d:
                d[i] = 0
            d[i] += 1
        
        g = 0
        for i in d:
            g = math.gcd(g, d[i])

        return g > 1
