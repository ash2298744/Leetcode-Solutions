class Solution:
    def pseudoPalindromicPaths (self, root: Optional[TreeNode]) -> int:
        freq = [0 for i in range(9)]
        def dfs(node):
            if not node: 
                return 0

            freq[node.val - 1] += 1
            if(node.left == None and node.right == None):
                oddCnt = 0
                for i in freq:
                    if i % 2 != 0:
                        oddCnt += 1
                freq[node.val - 1] -= 1
                return int(oddCnt <= 1)

            left = dfs(node.left)
            right = dfs(node.right)
            freq[node.val - 1] -= 1
            return left + right
            
        return dfs(root)