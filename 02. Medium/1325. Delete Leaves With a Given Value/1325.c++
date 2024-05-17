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
    bool dfs(TreeNode* node, int target) {
        if(node == NULL) return false;
        bool l = dfs(node -> left, target);
        bool r = dfs(node -> right, target);
        if(l) node -> left = NULL;
        if(r) node -> right = NULL;
        if(node -> left == NULL && node -> right == NULL) {
            return node -> val == target;
        }
        return false;
    }

    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        dfs(root, target);
        if(root -> left == NULL && root -> right == NULL && root -> val == target) {
            return NULL;
        }
        return root;
    }
};

