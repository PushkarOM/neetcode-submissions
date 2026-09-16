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
    int d = 0;

    int dfs(TreeNode* node){
        if(node == nullptr) return 0;

        int left = dfs(node->left);
        int right = dfs(node->right);

        d = max(left + right, d);

        return max(left,right) + 1;
        
    }

    int diameterOfBinaryTree(TreeNode* root) {
       
        int height = dfs(root);
        return d;

    }
};
