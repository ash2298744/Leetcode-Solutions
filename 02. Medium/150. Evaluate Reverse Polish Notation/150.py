class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        def solve(a, b, op):
            if op == "+": return a + b
            elif op == '-': return a - b
            elif op == '*': return a * b
            else: return int(a / b)

        stack = []
        for i in tokens:
            if i in "+*/-":
                stack[-2] = solve(stack[-2], stack[-1], i)
                stack.pop()
            else:
                stack.append(int(i))
        return stack[-1]
    