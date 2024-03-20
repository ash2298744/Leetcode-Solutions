# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeInBetween(self, head: ListNode, a: int, b: int, list2: ListNode) -> ListNode:
        b = b - a + 1
        a -= 1

        curr1 = head
        while curr1 and a:
            curr1 = curr1.next
            a -= 1

        curr2 = curr1
        while curr2 and b:
            curr2 = curr2.next
            b -= 1

        curr1.next = list2
        while curr1.next:
            curr1 = curr1.next
        curr1.next = curr2.next
        return head
             