class Solution {
public:

 void solve(vector<int> & candidates, int index, int remaining, vector<int>& path, vector<vector<int>>&ans){
    if(remaining==0){
        ans.push_back(path);
        return;
    }
    if(remaining<0){
        return;
    }

    for(int i= index; i<candidates.size();i++){
        path.push_back(candidates[i]);
        solve(candidates, i, remaining-candidates[i], path, ans);
        path.pop_back();
    }
 }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>path;
        vector<vector<int>>ans;
       solve(candidates, 0, target, path, ans);
       return ans;
    }
};