/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    // parent mapping banane ke liye
    unordered_map<TreeNode*, TreeNode*> parent;

    void makeParent(TreeNode* node) {

        if(node == NULL)
            return;

        if(node->left) {
            parent[node->left] = node;
            makeParent(node->left);
        }

        if(node->right) {
            parent[node->right] = node;
            makeParent(node->right);
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {

        vector<int> ans;

        // Step 1: parent mapping
        makeParent(root);

        // Step 2: BFS start from target
        queue<TreeNode*> q;
        q.push(target);

        // Step 3: visited
        unordered_set<TreeNode*> visited;
        visited.insert(target);

        int distance = 0;

        while(!q.empty()) {

            int size = q.size();

            // Agar required distance aa gaya
            if(distance == k) {

                for(int i = 0; i < size; i++) {

                    TreeNode* node = q.front();
                    q.pop();

                    ans.push_back(node->val);
                }

                return ans;
            }

            // Current level ke saare nodes process karo
            for(int i = 0; i < size; i++) {

                TreeNode* node = q.front();
                q.pop();

                // Left child
                if(node->left != NULL &&
                   visited.find(node->left) == visited.end()) {

                    q.push(node->left);
                    visited.insert(node->left);
                }

                // Right child
                if(node->right != NULL &&
                   visited.find(node->right) == visited.end()) {

                    q.push(node->right);
                    visited.insert(node->right);
                }

                // Parent
                if(parent.find(node) != parent.end() &&
                   visited.find(parent[node]) == visited.end()) {

                    q.push(parent[node]);
                    visited.insert(parent[node]);
                }
            }

            distance++;
        }

        return ans;
    }
};