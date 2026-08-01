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
    vector<vector<int>> levelOrder(TreeNode* root) {
     vector<vector<int>>ans;//ans mein [[3],[9,20],[null,15,7]] aa rha its vector inside vector
     queue<TreeNode*> q;//hme childerne tk jana hai isliye ques mein treenode store hoga

     q.push(root);//root ko queue mein dalo


//      Lekin ek edge case.

// Agar tree hi empty ho?

if(root == NULL)
    return ans;


    while(!q.empty())//Jab tak process karne ke liye nodes bache hain.
    {
        int n = q.size();
        vector<int> level;//Isme sirf current level ki values aayengi.


        for(int i=0;i<n;i++)//sirf current level ke nodes process kro
{
    TreeNode* node = q.front();
q.pop();//front node nikalo

// Answer mein add karo
level.push_back(node->val);
// Left child
if(node->left != NULL)
    q.push(node->left);
// Step 11: Right child
if(node->right != NULL)
    q.push(node->right);
}
// Level complete
ans.push_back(level);
    }
return ans;//while loop end queue empty
    }
};