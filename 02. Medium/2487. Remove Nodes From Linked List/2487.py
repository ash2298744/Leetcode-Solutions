# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def reverse(self, head):
        prev, curr = None, head
        while curr:
            temp = curr.next
            curr.next = prev
            prev = curr
            curr = temp
        return prev

    def removeNodes(self, head: Optional[ListNode]) -> Optional[ListNode]:
        newHead = self.reverse(head)

        mx = 0
        prev, curr = None, newHead
        while curr:
            mx = max(mx, curr.val)
            if mx > curr.val:
                if prev == None:
                    temp = curr.next
                    curr.next = None
                    curr = temp
                else:
                    prev.next = curr.next
                    curr = curr.next
            else:
                prev = curr
                curr = curr.next
        
        return self.reverse(newHead)
                