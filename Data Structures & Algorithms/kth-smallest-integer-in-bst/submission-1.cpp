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
    int kthSmallest(TreeNode* root, int k) {
        int count = 0;
        int ans;
        dfs(root, count, ans, k);
        return ans;
    }

    void dfs(TreeNode* node, int& count, int& ans, int k) {
        if (!node) return;
        dfs(node->left, count, ans, k);
        count++;
        if (count == k) {
            ans = node->val;
            return;
        }
        dfs(node->right, count, ans, k);
    }
};
