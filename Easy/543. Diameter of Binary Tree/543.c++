#include<bits/stdc++.h>;
using namespace std;

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
    int dfs(TreeNode* node, int& ans) {
        if(node == NULL) return 0;
        int left = dfs(node -> left, ans);
        int right = dfs(node -> right, ans);
        ans = max(ans, left + right);
        return 1 + max(left, right);
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        dfs(root, ans);
        return ans;
    }
};