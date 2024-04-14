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
    void dfs(TreeNode *node, int &sum) {
        if(node == NULL) return;
        if(node -> left && !node -> left -> left && !node -> left -> right) sum += node -> left -> val;
        dfs(node -> left, sum);
        dfs(node -> right, sum);
    }

    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        dfs(root, sum);
        return sum;
    }
};
