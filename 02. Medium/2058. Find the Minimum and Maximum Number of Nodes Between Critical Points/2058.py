# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def nodesBetweenCriticalPoints(self, head: Optional[ListNode]) -> List[int]:
        first = last = -1
        idx = 2
        prev = head
        curr = head.next

        mi = inf
        mx = -inf
        while curr.next:
            if (curr.val < prev.val and curr.val < curr.next.val) or (curr.val > prev.val and curr.val > curr.next.val):
                if first == -1:
                    first = idx

                if last != -1:
                    mi = min(mi, idx - last)
                    mx = max(mx, idx - first)

                last = idx
            prev = curr
            curr = curr.next
            idx += 1
        
        if first != last:
            return [mi, mx]
        return [-1, -1]
             