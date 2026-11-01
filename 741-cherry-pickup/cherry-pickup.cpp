class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
         int n=grid.size();
vector<vector<vector<int>>> dp(
    2*n-1,
    vector<vector<int>>(n, vector<int>(n, -1e9))
);
   if(grid[0][0]==-1) return 0;
      dp[0][0][0]=grid[0][0]; 
            for(int k=0;k<2*n-1;k++){
                if(k==0)continue; 
                for(int i=0;i<n;i++){
                    for(int j=0;j<n;j++){ 
                        int c1=k-i; 
                        int c2=k-j; 
                        if(c1<0 || c2<0||c1>=n||c2>=n){
                             continue;
                             }
                              if(grid[i][c1]==-1||grid[j][c2]==-1){
                                continue;
                                }  
                            

                            int best = -1e9;

// Right, Right
best = max(best, dp[k-1][i][j]);

// Right, Down
if(j > 0) {
    best = max(best, dp[k-1][i][j-1]);
}

// Down, Right
if(i > 0) {
    best = max(best, dp[k-1][i-1][j]);
}

// Down, Down
if(i > 0 && j > 0) {
    best = max(best, dp[k-1][i-1][j-1]);
}

// No valid previous state
if(best == -1e9) continue;

int cherries; 
 if(i==j && c1==c2){ 
    cherries=grid[i][c1]; 
    } else{
         cherries=grid[i][c1]+grid[j][c2];
         }  
          dp[k][i][j]=best+cherries;
          }}   }
          
          return max(0, dp[2*n-2][n-1][n-1]);         

    }
};