class Deque:
    
    def __init__(self):
        self.head = self.tail = None

    def isEmpty(self) -> bool:
        if self.head is not None:
            return False
        return True

    def append(self, value: int) -> None:
        newNode = Node(value, None, None)
        if self.head is None:
            self.tail = newNode
            self.head = newNode
        else:
            newNode.next = self.head
            self.head.prev = newNode
            self.head = newNode

    def appendleft(self, value: int) -> None:
        newNode = Node(value, None, None)
        if self.head is None:
            self.tail = newNode
            self.head = newNode
        else:
            temp = self.tail
            self.tail.next = newNode
            self.tail = newNode
            self.tail.prev = temp

    def pop(self) -> int:
        if self.head is None: 
            return -1
        pop = self.head.val
        if self.head == self.tail:
            self.head = None
            self.tail = None
            return pop
        self.head = self.head.next
        return pop

    def popleft(self) -> int:
        if self.head is None:
            return -1
        pop = self.tail.val
        if self.head == self.tail:
            self.head = None
            self.tail = None
            return pop
        self.tail = self.tail.prev
        return pop

class Node:

    def __init__(self, val, next, prev):
        self.val = val 
        self.next = next
        self.prev = prev