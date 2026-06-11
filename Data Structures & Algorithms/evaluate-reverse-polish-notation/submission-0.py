class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        stack = []
        for i in range(len(tokens)):
            token = tokens[i]
            if token.lstrip('-').isdigit():
                stack.append(int(token))
            else:
                b = stack.pop()
                a = stack.pop()
                compute = 0
                if token == "*":
                    compute = a * b
                elif token == "+":
                    compute = a + b
                elif token == "/":
                    compute = int(a / b)
                else:
                    compute = a - b
                stack.append(compute)
        return  stack[-1]   