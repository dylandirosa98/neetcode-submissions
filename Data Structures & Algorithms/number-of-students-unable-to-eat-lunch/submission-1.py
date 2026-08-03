class Solution:
    def countStudents(self, students: List[int], sandwiches: List[int]) -> int:
        queue = Queue()
        for i in students:
            if not queue.head:
                queue.tail = Node(i)
                queue.head = queue.tail
            else:
                queue.tail.next = Node(i)
                queue.tail = queue.tail.next
        counter = 0
        sandwiches.reverse()
        while counter < len(sandwiches):
            counter += 1
            if sandwiches[-1] == queue.head.val:
                sandwiches.pop()
                queue.head = queue.head.next
                counter = 0
            else:
                temp = queue.head 
                queue.head = queue.head.next
                queue.tail.next = temp
                temp.prev = queue.tail
                queue.tail = temp
        return len(sandwiches)

class Queue:

    def __init__(self):
        self.tail = self.head = None


class Node:

    def __init__(self, val, prev=None, next=None):
        self.val = val
        self.prev = prev
        self.next = next