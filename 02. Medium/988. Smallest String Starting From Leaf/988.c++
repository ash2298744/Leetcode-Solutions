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
    void dfs(TreeNode *node, string s, vector<string> &arr) {
        if(node == NULL) return;
        if(!node -> left && !node -> right) {
            arr.push_back(char(node -> val + 97) + s);
            return;
        }
        dfs(node -> left, char(node -> val + 97) + s, arr);
        dfs(node -> right, char(node -> val + 97) + s, arr);
    }

    string smallestFromLeaf(TreeNode* root) {
        vector<string> arr;
        dfs(root, "", arr);
        sort(arr.begin(), arr.end());
        return arr[0];
    }
};