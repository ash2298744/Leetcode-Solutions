class Solution:
    def minimumChairs(self, s: str) -> int:
        ans = cnt = 0
        for i in s:
            if i == "E":
                cnt += 1
            else:
                cnt -= 1
            ans = max(ans, cnt)
        return ans
