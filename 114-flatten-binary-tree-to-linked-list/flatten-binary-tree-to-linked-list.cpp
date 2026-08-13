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
TreeNode* prev=NULL;
void solve(TreeNode* root){
    if(root==NULL)
    return;

         // Reverse preorder
        solve(root->right);
        solve(root->left);

        // Current node ko already processed
        // node ke aage attach karo
        root->right = prev;
        root->left = NULL;

        prev = root;
}
    void flatten(TreeNode* root) {
           solve(root);
     
    }
};