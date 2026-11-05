class Solution {
public:
int solve(int i, int j, string &s, vector<vector<int>>& dp){
    if(i>=j) return 0;
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    if(s[i]==s[j]){
        dp[i][j]= solve(i+1, j-1, s, dp);
    }else{
        dp[i][j]=1+min(solve(i,j-1,s,dp), solve(i+1,j,s,dp));
    }
    return dp[i][j];
}
    int minInsertions(string s) {
        int n= s.size();
        vector<vector<int>>dp(n, vector<int>(n,-1));
        return solve(0, n-1, s, dp);
    }
};