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
    
    bool inOrderTraversal(TreeNode* node, long long& prev) {
        if (node == nullptr)
            return true;

        if (!inOrderTraversal(node->left, prev))
            return false;

        if (node->val <= prev)
            return false;

        prev = node->val;

        if (!inOrderTraversal(node->right, prev))
            return false;

        return true;
    }


    bool isValidBST(TreeNode* root) {
        
        long long val = LLONG_MIN;

        return inOrderTraversal(root, val);
    }
};
