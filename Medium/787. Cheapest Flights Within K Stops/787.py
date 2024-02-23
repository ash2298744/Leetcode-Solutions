class Solution:
    def findCheapestPrice(self, n: int, flights: List[List[int]], src: int, dst: int, k: int) -> int:
        k += 1
        dp = [[float('inf') for i in range(k + 1)] for i in range(n)]
        dp[src][0] = 0
        for i in range(1, k + 1):
            for flight in flights:
                start, end, cost = flight
                dp[end][i] = min(dp[end][i], dp[start][i - 1] + cost)
        ans = min(dp[dst])
        return ans if ans != float('inf') else -1
