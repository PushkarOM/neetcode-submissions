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
    
    void inOrderTraversal(TreeNode* node, vector<int>& arr){
        if(node == nullptr) return;

        inOrderTraversal(node->left, arr);
        arr.push_back(node->val);
        inOrderTraversal(node->right, arr);

    }


    bool isValidBST(TreeNode* root) {
        vector<int> arr;
        inOrderTraversal(root, arr);

        for(int i = 1; i < arr.size(); i++){
            if(arr[i-1] >= arr[i]){
                return false;
            }
        }

        return true;
    }
};
