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
    bool isCousins(TreeNode* root, int x, int y) 
    {
if(root==NULL)
return NULL;

 queue<TreeNode*>q;
 q.push(root);
 while(!q.empty()){
    int size=q.size();
    bool foundx=false;
    bool foundy=false;
    TreeNode* parentx=NULL;
    TreeNode* parenty=NULL;
    for(int i=0;i<size;i++){
        TreeNode* node = q.front();
        q.pop();
        if(node->left){
            if(node->left->val==x){
                foundx=true;
                parentx=node;
            }
            if(node->left->val==y){
                foundy=true;
                parenty=node;
            }
            q.push(node->left);
        }
        if(node->right){
            if(node->right->val==x){
                foundx=true;
                parentx=node;
            }
            if(node->right->val==y){
                foundy=true;
                parenty=node;
            }

            q.push(node->right);
        }
    }
    if(foundx && foundy){
        return parentx!=parenty;
    }
    if(foundx||foundy){
        return false;
    }
 }
    return false;
 
    }
};