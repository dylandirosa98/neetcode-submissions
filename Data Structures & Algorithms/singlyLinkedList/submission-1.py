class LinkedList:
    
    def __init__(self):
        self.head = LinkedNode(-1, None)
        self.tail = self.head

    
    def get(self, index: int) -> int:
        cur = self.head
        for i in range(index + 1):
            if cur.nextnode == None:
                return -1
            cur = cur.nextnode
        return cur.val

    def insertHead(self, val: int) -> None:
        newHead = LinkedNode(val, self.head.nextnode)
        if self.head == self.tail:
            self.tail = newHead
        self.head.nextnode = newHead


    def insertTail(self, val: int) -> None:
        newTail = LinkedNode(val, None)
        self.tail.nextnode = newTail
        self.tail = newTail

    def remove(self, index: int) -> bool:
        cur = self.head
        for i in range(index):
            if cur.nextnode == None:
                return False
            cur = cur.nextnode
        if cur.nextnode == None:
            return False
        if cur.nextnode == self.tail:
            self.tail = cur
        cur.nextnode = cur.nextnode.nextnode
        return True

    def getValues(self) -> List[int]:
        cur = self.head
        theList = []
        while cur.nextnode != None:
            theList.append(cur.nextnode.val)
            cur = cur.nextnode
        return theList

class LinkedNode:
    def __init__(self, val, nextnode):
        self.val = val
        self.nextnode = nextnode
