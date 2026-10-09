class Solution {
public:
void solve(vector<int>& nums, int index, vector<int>& path, vector<vector<int>>& ans){
    ans.push_back(path);
    for(int i=index; i<nums.size();i++){

    if(i>index && nums[i]==nums[i-1])
    continue;

    path.push_back(nums[i]);
    solve(nums, i+1, path, ans);
    path.pop_back();
    }
}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int>path;
        vector<vector<int>>ans;
        sort(nums.begin(), nums.end());
        solve(nums, 0, path, ans);
        return ans;
    }
};