class Solution {
public:
void solve(vector<int>& nums, vector<int>& path, vector<int>& used,  vector<vector<int>>& ans){
    if(nums.size()==path.size()){
        ans.push_back(path);
        return;
    }
for(int i=0;i<nums.size();i++){
    if(used[i])continue;
    if(i>0 && nums[i]==nums[i-1] && !used[i-1]){
        continue;
    }
    path.push_back(nums[i]);
    used[i]=true;
    solve(nums, path, used, ans);
    used[i]=false;
    path.pop_back();

}
}
    vector<vector<int>> permuteUnique(vector<int>& nums) {

        // Duplicate elements ko adjacent lane ke liye
        sort(nums.begin(), nums.end());

        vector<vector<int>>ans;
        vector<int>path;
        vector<int>used(nums.size(), false);

        solve(nums, path, used, ans);
        return ans;

    }
};