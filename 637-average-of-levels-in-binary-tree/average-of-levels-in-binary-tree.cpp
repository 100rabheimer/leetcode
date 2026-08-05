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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double>ans;
            // Base case
        if(root == NULL)
            return ans;
            queue<TreeNode*>q;
                 q.push(root);

        while(!q.empty())
        {
            // Number of nodes in current level
            int size = q.size();
                long long sum = 0;

            // Process current level
            for(int i = 0; i < size; i++)
            {
                TreeNode* node = q.front();
                q.pop();

                // Add current node value
                sum += node->val;

                // Push left child
                if(node->left)
                    q.push(node->left);

                // Push right child
                if(node->right)
                    q.push(node->right);
            }

            // Store average
            ans.push_back((double)sum / size);}
            return ans;
    }
};