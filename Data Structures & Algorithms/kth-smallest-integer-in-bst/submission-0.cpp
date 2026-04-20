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
        // We can use DFS. Go deep and then count
        std::vector<int> arr;
        helper(root, arr);
        return arr[k - 1];
    }

private: 
    void helper(TreeNode* root, std::vector<int> &arr) {
        if (!root) {
            return;
        }
        helper(root->left, arr);
        arr.push_back(root->val);
        helper(root->right, arr);
    }
};
