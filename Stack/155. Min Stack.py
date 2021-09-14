# https://leetcode.com/problems/min-stack/
class MinStack:
    # Instead of storing only the values, we store 
    # the minimum of the stack up to that value.
    
    def __init__(self):
        self.stack = [(0, 10 ** 10)]

    def push(self, val: int) -> None:
        # Append the current val and calculate the new min
        self.stack.append((val, min(val, self.stack[-1][1])))

    def pop(self) -> None:
        self.stack.pop()

    def top(self) -> int:
        return self.stack[-1][0]

    def getMin(self) -> int:
        return self.stack[-1][1]
