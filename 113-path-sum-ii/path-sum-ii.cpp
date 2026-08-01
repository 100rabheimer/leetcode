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

    void dfs(TreeNode* root, int targetSum,
             vector<int>& path,
             vector<vector<int>>& ans) {

        // Base case
        if (root == NULL)
            return;

        // Current node ko path me add karo
        path.push_back(root->val);

        // Agar leaf node hai
        if (root->left == NULL && root->right == NULL) {

            // Aur sum bhi match ho gaya
            if (root->val == targetSum) {
                ans.push_back(path);
            }

            // Backtracking
            path.pop_back();
            return;
        }

        // Left subtree
        dfs(root->left, targetSum - root->val, path, ans);

        // Right subtree
        dfs(root->right, targetSum - root->val, path, ans);

        // Wapas jaate waqt current node ko hata do
        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {

        vector<vector<int>> ans;
        vector<int> path;

        dfs(root, targetSum, path, ans);

        return ans;
    }
};