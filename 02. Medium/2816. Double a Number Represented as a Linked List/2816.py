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

    def doubleIt(self, head: Optional[ListNode]) -> Optional[ListNode]:
        newHead = self.reverse(head)

        prev = newHead
        carry = 0
        while prev:
            t = prev.val
            prev.val = (t + t) % 10 + carry
            carry = (t + t) // 10
            prev = prev.next

        return self.reverse(newHead) if not carry else ListNode(1, self.reverse(newHead))
