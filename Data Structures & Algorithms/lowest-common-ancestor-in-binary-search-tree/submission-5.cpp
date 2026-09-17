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

    TreeNode* dfs(TreeNode* node, TreeNode* p, TreeNode* q){

        if(node == nullptr) return nullptr;

        if(p->val > node->val){
            if(q->val > node->val){
                return dfs(node->right,p,q);
            }
            else{
                return node;
            }
        }
        else if(p->val < node->val){
            if(q->val >= node->val){
                return node;
                
            }
            else{
                return dfs(node->left,p,q);
            }
        }
        else if(p->val == node->val){
            return p;
        }
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
           TreeNode* lca = dfs(root, p, q);
           return lca;
    }
};
