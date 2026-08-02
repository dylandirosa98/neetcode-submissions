class MyLinkedList:

    def __init__(self):
        self.head = ListNode(-1, None, None)
        self.tail = ListNode(-1, None, self.head)
        self.head.next = self.tail

    def get(self, index: int) -> int:
        curr = self.head.next
        for i in range(index):
            curr = curr.next if curr.next else ListNode(-1, None, None)
        return curr.val

    def addAtHead(self, val: int) -> None:
        temp = self.head.next
        newHead = ListNode(val, self.head.next, self.head)
        temp.prev = newHead
        self.head.next = newHead

    def addAtTail(self, val: int) -> None:
        temp = self.tail.prev
        newTail = ListNode(val, self.tail, self.tail.prev)
        temp.next = newTail
        self.tail.prev = newTail

    def addAtIndex(self, index: int, val: int) -> None:
        if index == 0:
            return self.addAtHead(val)
        curr = self.head
        for i in range(index):
            if curr.next == self.tail:
                return
            curr = curr.next
        curr = curr.next
        if curr.val == -1:
            return self.addAtTail(val)
        newValue = ListNode(val, curr, curr.prev)
        temp = curr.prev
        othertemp = curr
        othertemp.prev = newValue
        temp.next = newValue

    def deleteAtIndex(self, index: int) -> None:
        curr = self.head.next 
        for i in range(index):
            curr = curr.next if curr.next else ListNode(-1, None, None)
        if curr.val == -1:
            return
        temp = curr.prev
        othertemp = curr.next
        temp.next = curr.next
        othertemp.prev = temp


class ListNode:

    def __init__(self, val, next, prev):
        self.val = val
        self.next = next
        self.prev = prev 
# Your MyLinkedList object will be instantiated and called as such:
# obj = MyLinkedList()
# param_1 = obj.get(index)
# obj.addAtHead(val)
# obj.addAtTail(val)
# obj.addAtIndex(index,val)
# obj.deleteAtIndex(index)