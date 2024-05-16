# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def evaluateTree(self, root: Optional[TreeNode]) -> bool:
        def dfs(node):
            if not node: return
            dfs(node.left)
            dfs(node.right)
            if node.val == 2: node.val = node.left.val | node.right.val
            elif node.val == 3: node.val = node.left.val & node.right.val
        dfs(root)
        return root.val
