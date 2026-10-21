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
vector<TreeNode*>solve(int n){
    if(n==1){
        return {new TreeNode(0)};
    }
      vector<TreeNode*> result;
      for(int leftsize=1;leftsize<n;leftsize+=2){
int rightsize=n-1-leftsize;
// generate all possible subtrees
vector<TreeNode*>leftTrees=solve(leftsize);
vector<TreeNode*>rightTrees=solve(rightsize);
for(auto left:leftTrees){
    for(auto right:rightTrees){
TreeNode* root=new TreeNode(0);
root->left=left;
root->right=right;
result.push_back(root);
    }
}

      }
      return result;
}
    vector<TreeNode*> allPossibleFBT(int n) {
       if(n%2==0){
        return {};
       }
       return solve(n);
    }
};