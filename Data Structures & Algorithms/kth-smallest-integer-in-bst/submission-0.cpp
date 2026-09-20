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

    int inOrderTraversal(TreeNode* node, int k, int& count){

        if(node == nullptr) return -1;
        int result;

        result = inOrderTraversal(node->left, k, count);
        if(result != -1) return result;

        count++;
        if(count == k) return node->val;

        result = inOrderTraversal(node->right, k, count);
        if(result != -1) return result;
        
        return -1;
    }

    int kthSmallest(TreeNode* root, int k) {
        int count = 0;
        return inOrderTraversal(root, k, count);
    }
};
