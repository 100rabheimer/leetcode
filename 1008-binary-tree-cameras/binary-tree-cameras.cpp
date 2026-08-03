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
int cameras=0;
int min_camera(TreeNode* root){
    if(root==NULL){
        return 1;
    }
    int lc=min_camera(root->left);
    int rc=min_camera(root->right);

    if(lc==-1 || rc==-1){
        cameras++;
        return 0;
    }
    if(lc==0||rc==0){
        return 1;
    }
    return -1;
}
    int minCameraCover(TreeNode* root) {
        if(min_camera(root)==-1){
            cameras++;
            
        }
        return cameras;
    }
};