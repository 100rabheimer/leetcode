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

    int preIndex = 0;

    TreeNode* build(vector<int>& preorder,
                    vector<int>& inorder,
                    int inStart,
                    int inEnd) {

        // No elements left
        if (inStart > inEnd) {
            return NULL;
        }

        // Preorder ka current element ROOT hai
        int rootValue = preorder[preIndex];
        preIndex++;

        TreeNode* root = new TreeNode(rootValue);

        // Inorder mein root ko find karo
        int rootIndex = inStart;

        while (inorder[rootIndex] != rootValue) {
            rootIndex++;
        }

        // Root ke LEFT wale elements
        // left subtree banayenge
        root->left = build(preorder,
                           inorder,
                           inStart,
                           rootIndex - 1);

        // Root ke RIGHT wale elements
        // right subtree banayenge
        root->right = build(preorder,
                            inorder,
                            rootIndex + 1,
                            inEnd);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder,
                        vector<int>& inorder) {

        return build(preorder,
                     inorder,
                     0,
                     inorder.size() - 1);
    }
};