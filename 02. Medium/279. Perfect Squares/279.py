class Solution:
    def numSquares(self, n: int) -> int:
        t = 1
        while t * t <= n:
            t += 1
        
        q = deque([[n, 0]])
        vis = set()
        while q:
            num, cnt = q.popleft()

            if num == 0:
                return cnt

            for i in range(1, t):
                temp = i * i
                if num >= temp and (num - temp) not in vis:
                    vis.add(num - temp)
                    q.append([num - temp, cnt + 1])
        return -1
