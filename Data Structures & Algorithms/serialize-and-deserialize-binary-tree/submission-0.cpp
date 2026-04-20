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

class Codec {
public:

    // Encodes a tree to a single string.
    std::string serialize(TreeNode* root) {
        std::string res;
        s_dfs(root, res);
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(std::string data) {
        if (data.empty()) return nullptr;
        std::stringstream ss(data);
        return d_dfs(ss);
    }

private:
    void s_dfs(TreeNode* node, std::string &res) {
        
        if (!node) {
            res += "N,";
            return;
        }

        res += to_string(node->val) + ",";

        s_dfs(node->left, res);
        s_dfs(node->right, res);
    }

    TreeNode* d_dfs(std::stringstream& ss) {
        std::string s;

        if (!std::getline(ss, s, ',')) return nullptr;

        if (s == "N") return nullptr;

        TreeNode* node = new TreeNode(std::stoi(s));

        node->left = d_dfs(ss);
        node->right = d_dfs(ss);

        return node;
    }

};
