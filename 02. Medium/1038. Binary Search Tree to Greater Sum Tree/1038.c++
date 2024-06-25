/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int dfs(TreeNode* node, int &tot) {
        if(node == NULL) return 0;
        dfs(node -> right, tot);
        tot += node -> val;
        node -> val = tot;
        dfs(node -> left, tot);
        return tot;
    }

    TreeNode* bstToGst(TreeNode* root) {
        int tot = 0;
        dfs(root, tot);
        return root;
    }   
};
