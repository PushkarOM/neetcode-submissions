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
    bool check = true;

    int dfs(TreeNode* node){

        if(node == nullptr) return 0;

        int left = dfs(node->left);
        int right = dfs(node->right);

        check = check && abs(left - right) <= 1;
        
        return max(left, right) + 1;
    }

    bool isBalanced(TreeNode* root) {
        int height = dfs(root);
        return height == 0 ? true : check;
    }
};
