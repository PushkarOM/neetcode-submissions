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

    void multiTreeDfs(TreeNode* node1, TreeNode* node2){

            if(node1 == nullptr && node2 == nullptr){
                return;
            }
            else if(node1 == nullptr || node2 == nullptr){
                check = false;
                return;
            }

            check = check && node1->val == node2->val;

            multiTreeDfs(node1->left, node2->left);
            multiTreeDfs(node1->right, node2->right);
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        multiTreeDfs(p,q);
        return check;
    }
};
