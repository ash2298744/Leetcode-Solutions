class Solution:
    def maxProfitAssignment(self, difficulty: List[int], profit: List[int], worker: List[int]) -> int:
        arr = []
        for i, j in zip(difficulty, profit):
            arr.append([i, j])
        arr.sort(key = lambda x : x[0])

        maxProfit = []
        maxi = -inf
        for i in arr:
            maxi = max(maxi, i[1])
            maxProfit.append(maxi)

        n = len(arr)
        totalProfit = 0
        for i in worker:
            lo, hi = 0, n - 1
            while lo <= hi:
                mid = lo + (hi - lo) // 2
                if arr[mid][0] <= i:
                    lo = mid + 1
                else:
                    hi = mid - 1
            if hi != -1:
                totalProfit += maxProfit[hi]
        return totalProfit    
