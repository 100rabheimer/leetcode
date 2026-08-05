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
    bool isCousins(TreeNode* root, int x, int y) {

        // Base case
        if(root == NULL)
            return false;

        // Queue for BFS
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty())
        {
            int size = q.size();

            // Variables for current level only
            bool foundX = false;
            bool foundY = false;

            TreeNode* parentX = NULL;
            TreeNode* parentY = NULL;

            // Traverse current level
            for(int i = 0; i < size; i++)
            {
                TreeNode* node = q.front();
                q.pop();

                // Check left child
                if(node->left)
                {
                    if(node->left->val == x)
                    {
                        foundX = true;
                        parentX = node;
                    }

                    if(node->left->val == y)
                    {
                        foundY = true;
                        parentY = node;
                    }

                    q.push(node->left);
                }

                // Check right child
                if(node->right)
                {
                    if(node->right->val == x)
                    {
                        foundX = true;
                        parentX = node;
                    }

                    if(node->right->val == y)
                    {
                        foundY = true;
                        parentY = node;
                    }

                    q.push(node->right);
                }
            }

            // If both found in same level
            if(foundX && foundY)
                return parentX != parentY;

            // If only one found
            if(foundX || foundY)
                return false;
        }

        return false;
    }
};