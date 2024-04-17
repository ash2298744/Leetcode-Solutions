# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def smallestFromLeaf(self, root: Optional[TreeNode]) -> str:
        alpha = "abcdefghijklmnopqrstuvwxyz"
        ans = []

        def dfs(node, s):
            if not node:
                return
            if not node.left and not node.right:
                ans.append(alpha[node.val] + s)
                return
            dfs(node.left, alpha[node.val] + s)
            dfs(node.right, alpha[node.val] + s)

        dfs(root, "")
        return sorted(ans)[0]