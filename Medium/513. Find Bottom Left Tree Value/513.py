# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
        
class Solution:
    def findBottomLeftValue(self, root: Optional[TreeNode]) -> int:
        ans = [-1, -1]
        def dfs(node, depth):
            nonlocal ans
            if node == None: return 
            if node.left is None and node.right is None:
                if depth > ans[1]: ans = [node.val, depth]
            dfs(node.left, depth + 1)
            dfs(node.right, depth + 1)
        dfs(root, 0)
        return ans[0]
