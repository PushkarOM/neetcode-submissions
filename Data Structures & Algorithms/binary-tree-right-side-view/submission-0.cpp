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
   
    vector<int> rightSideView(TreeNode* root) {
        // use level order BFS taversal, and add the last child added to queue to the vector on each level

        if(root == nullptr) return vector<int>{};

        vector<int> ans;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {

            int levelSize = q.size();
            vector<int> level;

            for (int i = 0; i < levelSize; i++) {

                TreeNode* temp = q.front();
                q.pop();

                // add its value to level
                level.push_back(temp->val);

                // add left child
                if (temp->left)
                    q.push(temp->left);

    
                // add right child
                if (temp->right)
                    q.push(temp->right);
                
            }
            ans.push_back(level.back());
        }

        return ans;
    }
};
