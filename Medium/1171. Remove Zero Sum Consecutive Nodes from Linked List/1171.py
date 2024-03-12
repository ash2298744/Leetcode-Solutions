# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeZeroSumSublists(self, head: Optional[ListNode]) -> Optional[ListNode]:
        dummy = ListNode(-1, head)
        while 2024:
            curr, flag = dummy, False
            while curr and not flag:
                curr2, val = curr.next, 0
                while curr2 and not flag:
                    val += curr2.val
                    curr2 = curr2.next
                    if val == 0:
                        curr.next = curr2
                        flag = True
                curr = curr.next
            if not flag: break
        return dummy.next
        