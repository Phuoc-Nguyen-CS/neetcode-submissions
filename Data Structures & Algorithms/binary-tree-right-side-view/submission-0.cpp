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
        // BFS problem
        std::vector<int> result;
        std::queue<TreeNode*> q;

        if (root == nullptr) return result;
        q.push(root);

        while(!q.empty()) {
            // Add each row to the queue. 
            // Pop all and the last number on the queue should be the right most value 
            TreeNode* curr;
            for (int i = q.size(); i > 0; --i) {
                
                curr = q.front();
                q.pop();
                
                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);     
            }

            result.push_back(curr->val);
        }

        return result;
    }
};
