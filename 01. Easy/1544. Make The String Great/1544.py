class Solution:
    def makeGood(self, s: str) -> str:
        stack = []
        for i in s:
            if stack and stack[-1].lower() == i.lower() and ( (stack[-1].islower() and i.isupper()) or (stack[-1].isupper() and i.islower())):
                stack.pop()
                while len(stack) > 1 and stack[-1].lower() == stack[-2].lower() and ( (stack[-1].islower() and stack[-2].isupper()) or (stack[-1].isupper() and stack[-2].islower())):
                    stack.pop()
                    stack.pop()
            else:
                stack.append(i)
            
        return "".join(stack)
