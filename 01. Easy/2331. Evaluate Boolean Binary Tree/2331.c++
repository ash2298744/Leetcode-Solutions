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
    void dfs(TreeNode* node) {
        if(node == NULL) return;
        dfs(node -> left);
        dfs(node -> right);
        if(node -> val == 2) node -> val = node -> left -> val | node -> right -> val;
        else if(node -> val == 3) node -> val = node -> left -> val & node -> right -> val;
    }

    bool evaluateTree(TreeNode* root) {
        dfs(root);
        return root -> val;
    }
};
