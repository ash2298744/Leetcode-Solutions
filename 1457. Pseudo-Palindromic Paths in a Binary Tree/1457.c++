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
    int dfs(TreeNode* node, vector<int> f) {
        if(node == NULL) return 0;

        f[node -> val - 1]++;
        if(node -> left == NULL && node -> right == NULL) {
            int oddCnt = 0;
            for(int i = 0; i < 9; i++)
                oddCnt += (f[i] % 2 != 0);
            return oddCnt <= 1;
        }
        return dfs(node -> left, f) + dfs(node -> right, f);
        f[node -> val - 1]--;
    }

    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> f(10, 0);
        return dfs(root, f);
    }
};