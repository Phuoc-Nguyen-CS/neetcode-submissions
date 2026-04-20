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
    int maxPathSum(TreeNode* root) {
        int maxSum = root->val;
        dfs(root, maxSum);
        return maxSum;
    }

private:
    int dfs(TreeNode* node, int& maxSum) {
        // Go deep and keep the max of the two children
        if (!node) return 0;
        int leftSum = std::max(dfs(node->left, maxSum), 0);
        int rightSum = std::max(dfs(node->right, maxSum), 0);

        int currentPathSum = node->val + leftSum + rightSum;
        maxSum = std::max(maxSum, currentPathSum);

        return node->val + std::max(leftSum, rightSum);
    }
};
