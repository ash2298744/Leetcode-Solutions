class Solution:
    def mincostToHireWorkers(self, quality: List[int], wage: List[int], k: int) -> float:
        n = len(wage)
        arr = []
        for i in range(n):
            arr.append([(wage[i] / quality[i]), quality[i]])
        arr.sort()

        ans = inf
        currSum = 0
        hep = []
        heapq.heapify(hep)
        for i in arr:
            currSum += i[1]
            heapq.heappush(hep, -i[1])
            if len(hep) > k:
                currSum += heapq.heappop(hep)
            if len(hep) == k:
                ans = min(ans, currSum * i[0])
        return ans
