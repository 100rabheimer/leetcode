class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
     int m = dungeon.size();
int n = dungeon[0].size();
vector<vector<int>>dp(m, vector<int>(n,0));
  dp[m-1][n-1] = max(1, 1 - dungeon[m-1][n-1]);


for(int i = m-1; i >= 0; i--) {
    for(int j = n-1; j >= 0; j--) {

        if(i == m-1 && j == n-1)
            continue;

        int nextNeed;

        if(i == m-1) {
            // Last row
            nextNeed=dp[i][j+1];
        }
        else if(j == n-1) {
            // Last column
            nextNeed=dp[i+1][j];
        }
        else {
            // Normal cell
            nextNeed=min(dp[i+1][j],dp[i][j+1]);
        }

        dp[i][j] = max(1, nextNeed - dungeon[i][j]);
    }
}
return dp[0][0];
    }
};