class Solution:
    def maxDistance(self, position: List[int], m: int) -> int:
        def canPlace(force):
            cnt = 1
            prev = position[0]
            for i in position:
                if (i - prev) > force:
                    prev = i
                    cnt += 1
            return cnt < m
        
        position.sort()
        lo, hi = 1, 10 ** 10
        while lo <= hi:
            mid = (lo + hi) >> 1
            if canPlace(mid):
                hi = mid - 1
            else:
                lo = mid + 1
        return lo
