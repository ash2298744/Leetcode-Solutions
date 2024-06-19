class Solution:
    def minDays(self, bloomDay: List[int], m: int, k: int) -> int:
        def canMakeWithDay(day):
            currK = usedM = 0
            for i in bloomDay:
                if i <= day:
                    currK += 1
                    if currK == k:
                        currK = 0
                        usedM += 1
                else:
                    currK = 0
            return usedM >= m
    
        lo, hi = min(bloomDay), max(bloomDay)
        while lo <= hi:
            mid = (lo + hi) // 2
            if canMakeWithDay(mid):
                hi = mid - 1
            else:
                lo = mid + 1
        return lo if lo <= max(bloomDay) else -1
        