class Solution:
    def minRemoveToMakeValid(self, s: str) -> str:
        n = len(s)
        res = [i for i in s]

        stack = []
        for i in range(n):
            if s[i] == "(":
                stack.append(i)
            elif s[i] == ")":
                if stack and s[stack[-1]] == "(":
                    stack.pop()
                else:
                    stack.append(i)
            
        for i in stack:
            res[i] = ""
        
        return "".join(res)
