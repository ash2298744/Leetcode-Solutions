#include<bits/stdc++.h>;
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution {
public:
    void dfs(TreeNode* node, int depth, vector<int>& ans) {
        if(node == NULL) return;
        if(node -> left == NULL && node -> right == NULL) {
            if(depth > ans[1]) ans = {node -> val, depth};
            return;
        }
        dfs(node -> left, depth + 1, ans);
        dfs(node -> right, depth + 1, ans);
    }

    int findBottomLeftValue(TreeNode* root) {
        vector<int> ans = {-1, -1};
        dfs(root, 0, ans);
        return ans[0];
    }
};
