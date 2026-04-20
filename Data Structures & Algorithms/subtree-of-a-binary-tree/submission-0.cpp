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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        // Go through the tree until we find similar values
        // If none are found we can return false

        if(!root) return false;

        if (compare(root, subRoot)) return true;

        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }

private:
    bool compare(TreeNode* root, TreeNode* subRoot){
        if (!root && !subRoot) return true;

        if (root && subRoot && root->val == subRoot->val) {
            return compare(root->left, subRoot->left) && compare(root->right, subRoot->right);
        }
        else return false;
    }
};
