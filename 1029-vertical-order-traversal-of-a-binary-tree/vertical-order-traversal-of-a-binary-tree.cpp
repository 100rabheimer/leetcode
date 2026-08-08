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

    vector<tuple<int,int,int>> nodes;

    void dfs(TreeNode* node, int row, int col) {

        if(node == NULL)
            return;

        nodes.push_back({col, row, node->val});

        dfs(node->left, row + 1, col - 1);
        dfs(node->right, row + 1, col + 1);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {

        vector<vector<int>> ans;

        if(root == NULL)
            return ans;

        dfs(root, 0, 0);

        sort(nodes.begin(), nodes.end());

        vector<int> level;
        int currentCol = get<0>(nodes[0]);

        for(auto x : nodes) {

            if(get<0>(x) != currentCol) {
                ans.push_back(level);
                level.clear();
                currentCol = get<0>(x);
            }

            level.push_back(get<2>(x));
        }

        ans.push_back(level);

        return ans;
    }
};