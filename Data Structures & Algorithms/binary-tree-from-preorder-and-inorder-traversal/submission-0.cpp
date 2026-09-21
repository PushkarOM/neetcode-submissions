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
    TreeNode* solve(int left, int right, vector<int>& preorder, vector<int>& inorder, unordered_map<int,int>& mp, int& preIndex){

        if(left > right) return nullptr;

        int value = preorder[preIndex++];
        TreeNode* root = new TreeNode(value);

        // find that preorder element in inorder
        int mid = mp[value];

        root->left = solve(left, mid-1, preorder, inorder, mp, preIndex);
        root ->right = solve(mid+1, right, preorder, inorder, mp, preIndex);
         
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> mp;

        for(int i = 0; i < inorder.size(); i++){
            mp[inorder[i]] = i;
        }
        int preIndex = 0;

        TreeNode* root = solve(0,preorder.size()-1,preorder, inorder, mp, preIndex);

        return root;

    }
};
