class MinStack:

    def __init__(self):
        self.stack = []
        self.mini = 0

    def push(self, val: int) -> None:
        self.stack.append(val)
        if len(self.stack) == 1 or self.mini > val:
            self.mini = val
        

    def pop(self) -> None:
        pop = self.stack.pop()
        if pop == self.mini and len(self.stack) != 0:
            self.mini = min(self.stack)

    def top(self) -> int:
        return self.stack[len(self.stack)-1]

    def getMin(self) -> int:
        return self.mini
