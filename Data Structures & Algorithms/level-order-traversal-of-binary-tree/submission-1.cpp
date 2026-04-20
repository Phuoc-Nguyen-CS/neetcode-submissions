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
        
        std::queue<TreeNode*> q;
        std::vector<std::vector<int>> result;

        if(root == nullptr) return result;

        q.push(root);

        while(!q.empty()) {

            std::vector<int> currAns;

            for(int i = q.size(); i > 0; --i) {
                TreeNode* curr = q.front();
                q.pop();

                currAns.push_back(curr->val);
                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }
            
            result.push_back(currAns);
        }

        return result;
    }
};
