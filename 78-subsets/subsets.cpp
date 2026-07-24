class Solution {
public:

    vector<vector<int>> ans;
    vector<int> curr;

    void solve(int index, vector<int>& nums)
    {
        // Base Case
        if(index == nums.size())
        {
            ans.push_back(curr);
            return;
        }

        // Choice 1 : Take current element
        curr.push_back(nums[index]);
        solve(index + 1, nums);

        // Undo (Backtrack)
        curr.pop_back();

        // Choice 2 : Don't Take current element
        solve(index + 1, nums);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        solve(0, nums);
        return ans;
    }
};