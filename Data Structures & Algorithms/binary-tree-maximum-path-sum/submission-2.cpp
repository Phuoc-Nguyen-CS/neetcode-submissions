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
        int maxSum = root->val; // The maximum could just be the root on its own
        dfs(root, maxSum);
        return maxSum;
    }

private:
    int dfs(TreeNode* node, int& maxSum) {
        if (!node) return 0;
        // Calculate the left/right max
        // If its negative we assign it to 0 signaling we are not adding that to our path
        int leftSum = std::max(dfs(node->left, maxSum), 0);
        int rightSum = std::max(dfs(node->right, maxSum), 0);
        // Keeps track of the currentPathSum as the maxSum does not require the root to be the max
        int currentPathSum = node->val + leftSum + rightSum;
        maxSum = std::max(maxSum, currentPathSum);
        // We return the max of the two paths since we can't return both
        // Why? because that would require a split from the given parent node to both its children
        return node->val + std::max(leftSum, rightSum);
    }
};
