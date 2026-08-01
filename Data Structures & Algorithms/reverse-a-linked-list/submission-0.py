# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head == None:
            return None        
        stack = [head.val]
        while head.next != None:
            head = head.next
            stack.append(head.val)
        newhead = ListNode(stack[-1])
        cur = newhead
        for i in range(len(stack)-2, -1, -1):
            cur.next = ListNode(stack[i])
            cur = cur.next
        return newhead