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
int countfrom(TreeNode* root, long long targetSum){
    if(root==NULL)
    return 0;
    int count=0;
if(root->val==targetSum)
count++;

count+= countfrom(root->left, targetSum-root->val);
count+= countfrom(root->right, targetSum-root->val);
return count;

}
    int pathSum(TreeNode* root, int targetSum) {
     if(root==NULL)
     return 0;
     return countfrom(root, targetSum) + 
     pathSum(root->left, targetSum) + 
     pathSum(root->right, targetSum);   
    }
};