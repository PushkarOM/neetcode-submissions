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
    vector<vector<int>> levelOrder(TreeNode* root) {

        vector<vector<int>> ans;

        if(root == nullptr) return vector<vector<int>>{};

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

            ans.push_back(level);
        }

        return ans;
    }
};
