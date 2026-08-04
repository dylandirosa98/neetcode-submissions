class MyStack:

    def __init__(self):
        self.q1 = []
        self.q2 = []

    def push(self, x: int) -> None:
        self.q1.append(x)
        self.q2 = self.q1 + self.q2
        self.q1 = self.q2
        self.q2 =[]
        self.q2, self.q1 = self.q1, self.q2
    def pop(self) -> int:
        num = self.q2[0]
        self.q2 = self.q2[1:]
        return num

    def top(self) -> int:
        return self.q2[0]

    def empty(self) -> bool:
        if self.q2:
            return False
        return True


# Your MyStack object will be instantiated and called as such:
# obj = MyStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.empty()