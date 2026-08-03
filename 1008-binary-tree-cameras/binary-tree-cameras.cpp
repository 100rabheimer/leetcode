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

    // State Mapping
    // -1 = NEEDS_CAMERA
    //  0 = HAS_CAMERA
    //  1 = COVERED

    int cameras = 0;

    int dfs(TreeNode* root)
    {
        // NULL node ko already covered maanenge.
        if(root == NULL)
            return 1;

        // Bottom-Up DFS
        int left = dfs(root->left);
        int right = dfs(root->right);

        // Agar kisi bhi child ko camera chahiye,
        // to current node pe camera lagana padega.
        if(left == -1 || right == -1)
        {
            cameras++;
            return 0;          // HAS_CAMERA
        }

        // Agar kisi child ke paas camera hai,
        // to current node automatically covered hai.
        if(left == 0 || right == 0)
        {
            return 1;          // COVERED
        }

        // Agar dono children covered hain
        // aur kisi ke paas camera nahi hai,
        // to current node ko camera chahiye.
        return -1;             // NEEDS_CAMERA
    }

    int minCameraCover(TreeNode* root)
    {
        // Agar root bhi camera maang raha hai,
        // to uske liye extra camera lagana padega.
        if(dfs(root) == -1)
            cameras++;

        return cameras;
    }
};