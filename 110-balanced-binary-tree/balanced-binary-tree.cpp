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
int height(TreeNode* root){
     if (root == NULL)
            return 0;

        int leftht = height(root->left);
        int rightht = height(root->right);
        return 1 + max(leftht, rightht);
}
    bool isBalanced(TreeNode* root) {
        if(root==NULL)
        return true;
int leftheight=height(root->left);
int rightheight=height(root->right);
return abs(leftheight-rightheight)<=1 &&
       isBalanced(root->left) &&
       isBalanced(root->right);
    }
};