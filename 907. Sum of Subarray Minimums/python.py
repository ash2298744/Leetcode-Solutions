class Solution:
    def sumSubarrayMins(self, arr: List[int]) -> int:
        n = len(arr)
        nse, pge = [n for i in range(n)], [-1 for i in range(n)]

        stack = []
        for i in range(n - 1, -1, -1):
            while stack and arr[i] <= arr[stack[-1]]:
                stack.pop()
            
            if stack:
                nse[i] = stack[-1]
            
            stack.append(i)

        stack = []
        for i in range(n):
            while stack and arr[i] < arr[stack[-1]]:
                stack.pop()
            
            if stack:
                pge[i] = stack[-1]
            
            stack.append(i)

        MOD = pow(10, 9) + 7
        res = 0
        for i in range(n):
            l = i - pge[i] 
            r = nse[i] - i
            res = (res + l * r * arr[i]) % MOD
        return res