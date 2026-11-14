class Solution {
public:
int solve(int i, int target, vector<int>& nums, vector<vector<int>>& dp){
  if(i == 0) {
    if(target == 0 && nums[0] == 0) return 2;
    if(target == 0 || target == nums[0]) return 1;
    return 0;
}
    if(dp[i][target]!=-1)
    return dp[i][target];

    int notpick=solve(i-1, target,nums, dp);

    int pick=0;
    if(nums[i]<=target){
        pick=solve(i-1, target-nums[i], nums, dp);
    }
    return dp[i][target]=pick+notpick;
}
    int findTargetSumWays(vector<int>& nums, int target) {
       int totalsum=0;
       for(int x: nums){
        totalsum+=x;
       } 
      if(abs(target) > totalsum || (totalsum + target) % 2 != 0){
    return 0;
       }
      int newtarget = (totalsum + target) / 2;

int n = nums.size();

vector<vector<int>> dp(n, vector<int>(newtarget + 1, -1));

return solve(n-1, newtarget, nums, dp);
    
    
    }
};