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
    int goodNodes(TreeNode* root) {
        
        // Can we use BFS and then compare the before ? 
        std::queue<std::pair<TreeNode*, int>> q;
        if (root == nullptr) return 0;
        q.push({root, root->val});
        int numNodes = 1;

        while (!q.empty()) {
            std::pair<TreeNode*, int> currRoot = q.front();
            q.pop();
            if (currRoot.first->left){
                if (currRoot.first->left->val >= currRoot.second) numNodes++;
                q.push({currRoot.first->left, std::max(currRoot.second, currRoot.first->left->val)});  
            } 
            if (currRoot.first->right){
                if (currRoot.first->right->val >= currRoot.second) numNodes++;
                q.push({currRoot.first->right, std::max(currRoot.second, currRoot.first->right->val)});  
            } 
        }

        return numNodes;
    }
};
