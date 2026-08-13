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
    void flatten(TreeNode* root) {
        
        if(root == NULL)
            return;

        // Original right subtree save karo
        TreeNode* right = root->right;

        // Left subtree flatten karo
        flatten(root->left);

        // Flattened left ko right side mein shift karo
        root->right = root->left;
        root->left = NULL;

        // Right chain ke end tak jao
        TreeNode* temp = root;

        while(temp->right != NULL)
            temp = temp->right;

        // Original right subtree attach karo
        temp->right = right;

        // Ab original right subtree ko flatten karo
        flatten(right);
    }
};