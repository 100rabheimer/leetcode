class Solution {
public:
int solve(int i, int amount, vector<int>& coins, vector<vector<int>>& dp){
    // base cases
    if(amount==0)return 0;
    if(i==0){//if i==0 hai 
if(amount%coins[0]==0){//amount agar coins[0] se div hai 
return amount/coins[0];//kitne coins lgenge return kro
}
return 1e9;//max possible ans Hum ise infinity jaisi value maan rahe hain, taaki valid answer hamesha isse chhota ho.
}
if(dp[i][amount]!=-1){
    return dp[i][amount];
}
int pick=1e9;
if(coins[i]<=amount){
    pick=1+solve(i,amount-coins[i],coins,dp);//pick krke dobara use sikke se bche huye amount cover krne ko dekhenge
} 
int notpick=solve(i-1,amount, coins,dp);

return dp[i][amount]=min(pick,notpick);
}
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int ans=solve(n-1,amount,coins,dp);
        if(ans>=1e9) return -1;
        return ans;
    }
};