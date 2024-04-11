class Solution:
    def removeKdigits(self, num: str, k: int) -> str:
        q = deque()
        for i in num:
            while q and k and int(q[-1]) > int(i):
                q.pop()
                k -= 1
            q.append(i)

        while q and q[0] == "0":
            q.popleft()
        
        while k and q:
            q.pop()
            k -= 1

        return "".join(q) if q else "0"
