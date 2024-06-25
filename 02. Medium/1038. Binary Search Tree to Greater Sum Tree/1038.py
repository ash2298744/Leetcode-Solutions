# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def bstToGst(self, root: TreeNode) -> TreeNode:
        tot = 0
        def dfs(node):
            nonlocal tot
            if node == None: return 0
            dfs(node.right)
            tot += node.val
            node.val = tot
            dfs(node.left)
            return tot
        dfs(root)
        return root
        