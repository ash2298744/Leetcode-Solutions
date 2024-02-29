# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
        
class Solution:
    def isEvenOddTree(self, root: Optional[TreeNode]) -> bool:
        q = deque([root])
        level = 0
        while q:
            n = len(q)
            prev = inf if level % 2 else -inf
            for _ in range(n):
                node = q.popleft()

                if level % 2 == 0:
                    if node.val % 2 == 0 or node.val <= prev:
                        return False
                else:
                    if node.val % 2 != 0 or node.val >= prev:
                        return False

                prev = node.val
                if node.left: q.append(node.left)
                if node.right: q.append(node.right)

            level += 1
        return True
