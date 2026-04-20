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
    string serialize(TreeNode* root) {
        if (!root) return "N";
        std::string res;
        std::queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            TreeNode* curr = q.front(); q.pop();
            
            if (curr == nullptr) {
                res += "N,";
            } else {
                res += to_string(curr->val) + ",";
                q.push(curr->left);
                q.push(curr->right);
            }
        }

        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        std::stringstream ss(data);
        std::string s;
        getline(ss, s, ',');
        if (s == "N") return nullptr;
        TreeNode* root = new TreeNode(stoi(s));
        std::queue<TreeNode*> q;
        q.push(root);

        while(getline(ss, s, ',')) {
            TreeNode* node = q.front(); q.pop();
            if (s != "N") {
                node->left = new TreeNode(stoi(s));
                q.push(node->left);
            }
            getline(ss, s, ',');
            if (s != "N") {
                node->right = new TreeNode(stoi(s));
                q.push(node->right);
            }
        }
        return root;
    }
};
