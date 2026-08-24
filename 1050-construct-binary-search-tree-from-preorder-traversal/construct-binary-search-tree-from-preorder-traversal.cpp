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
int i=0;
TreeNode* build(vector<int>& preorder,int min, int max){
       // Current value allowed range mein nahi hai
        if (i == preorder.size() ||
            preorder[i] < min ||
            preorder[i] > max) {
            return NULL;
        }

        // Current value se root banao
        TreeNode* root = new TreeNode(preorder[i]);
        i++;
         // Left subtree
        root->left = build(preorder, min, root->val); 
         // Right subtree
        root->right = build(preorder, root->val, max);

        return root;
}
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return build(preorder, INT_MIN, INT_MAX);
    }
};