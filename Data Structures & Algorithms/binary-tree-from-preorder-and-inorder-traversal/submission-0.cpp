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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // Map value to indices 
        std::unordered_map<int, int> mp;
        int index = 0;
        // Store for O(1) lookups
        for (int i = 0; i < inorder.size(); ++i) {
            mp[inorder[i]] = i;
        }

        return dfs(preorder, 0, inorder.size() - 1, mp, index);
    }

    TreeNode* dfs(std::vector<int>& preorder, int left, int right, std::unordered_map<int, int>& mp, int& index) {
        if (left > right) return nullptr; 

        int rootVal = preorder[index++];
        TreeNode* root = new TreeNode(rootVal);

        int mid = mp[rootVal];

        root->left = dfs(preorder, left, mid - 1, mp, index);
        root->right = dfs(preorder, mid + 1, right, mp, index);

        return root;
    }
};
