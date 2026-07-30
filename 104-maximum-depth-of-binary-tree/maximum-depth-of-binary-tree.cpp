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
    int maxDepth(TreeNode* root) {
        if(root==NULL)
        return 0;
        int leftdepth=maxDepth(root->left);
        int rightdepth=maxDepth(root->right);
        return 1+max(leftdepth, rightdepth);//current node ka bhi 1 add hoga na liek if  3 ka right side ke depth ko btana hai na toh measure krenge 2 +1(3 ka) bhi include hoga;
            }
};