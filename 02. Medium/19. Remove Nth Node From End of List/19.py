# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
        
class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        slow = fast = head
        while True:
            if n and fast:
                fast = fast.next
                n -= 1
            else:
                while fast and fast.next:
                    fast = fast.next
                    slow = slow.next

                if not fast: return head.next
                elif slow.next: slow.next = slow.next.next
                else: slow.next = None
                break
        return head
        