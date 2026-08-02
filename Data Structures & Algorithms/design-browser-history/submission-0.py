class BrowserHistory:

    def __init__(self, homepage: str):
        self.homepage = Node(homepage, None, None)
        self.curr = self.homepage

    def visit(self, url: str) -> None:
        self.curr.next = Node(url, self.curr, None)
        self.curr = self.curr.next

    def back(self, steps: int) -> str:
        x = 0
        while self.curr.prev != None and x < steps:
            x += 1
            self.curr = self.curr.prev
        return self.curr.val

    def forward(self, steps: int) -> str:
        x = 0
        while self.curr.next != None and x < steps:
            x += 1
            self.curr = self.curr.next
        return self.curr.val

class Node:
    
    def __init__(self, val, prev, next):
        self.val = val
        self.prev = prev
        self.next = next
# Your BrowserHistory object will be instantiated and called as such:
# obj = BrowserHistory(homepage)
# obj.visit(url)
# param_2 = obj.back(steps)
# param_3 = obj.forward(steps)