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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return sameValue(p, q);
    }

private:
    bool sameValue(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;

        // Checks if the numbers match
        if (p && q && p->val == q->val) {
            return sameValue(p->left, q->left) && sameValue(p->right, q->right);
        } else {
            return false;
        }
    }
};
