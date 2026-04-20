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
// -- BFS psuedocode -- 
//         void search (Node root) {
//             Queue queue = new Queue();
//             root.marked = true;
//             queue.enqueue(root); // Adding to end of the queue

//             while (!queue.isEmpty()) { 
//                 Node r = queue.dequeue(); // Remove from the front of the queue
//                 visit(r);
//                 for each (Node n in r.adjacent) {
//                     if (n.marked == false) {
//                         n.marked = true;
//                         queue.enqueue(n);
//                     }
//                 }    
//             }
//         }

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        std::queue<TreeNode* > q;
        std::vector<std::vector<int>> ans;

        if(!root) return ans;

        q.push(root);

        while(!q.empty()) {
            std::vector<int> level;
            int size = q.size();

            for (int i = q.size(); i > 0; i--) {
                TreeNode* node = q.front();
                q.pop();
                if (node) {
                    level.push_back(node->val);
                    q.push(node->left);
                    q.push(node->right);
                }
            }

            if (!level.empty()) {
                ans.push_back(level);
            }
        }
        return ans;
    }
};
