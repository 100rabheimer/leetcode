class Solution {
public:
void solve(vector<int>& nums, int index, vector<int>& path, vector<vector<int>>& ans){

    //jab sare elements ka decision o jaye toh current path ek complete subset hota hai 
    if(index==nums.size()){
        ans.push_back(path);
        return;
    }

    path.push_back(nums[index]);
   solve(nums, index+1, path, ans);
   path.pop_back();
solve(nums, index+1, path, ans);
}
    vector<vector<int>> subsets(vector<int>& nums) {
      vector<int>path;
      vector<vector<int>>ans;
      solve(nums, 0, path, ans);
      return ans;  
    }
};