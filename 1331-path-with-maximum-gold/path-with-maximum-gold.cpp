class Solution {
public:
void dfs(vector<vector<int>>& grid, int r, int c, int sum, int& ans){
  int m=grid.size();
       int n=grid[0].size();
       int gold=grid[r][c];
       sum += gold;
       grid[r][c]=0;
       ans=max(ans, sum);
       int dr[]={-1,1,0,0};
       int dc[]={0,0,-1,1};
for(int i=0;i<4;i++){
    int nr=r+dr[i];
    int nc=c+dc[i];
    if(nr>=0 && nr<m && nc>=0 && nc<n && grid[nr][nc]>0){
dfs(grid,nr,nc, sum,ans);
    }
}
grid[r][c]=gold;
}
    int getMaximumGold(vector<vector<int>>& grid) {
       int m=grid.size();
       int n=grid[0].size();
       int ans=0;
       for(int i=0;i<m;i++){
        for(int j=0;j<n;j++ ){
            if(grid[i][j]>0){
                dfs(grid,i,j,0,ans);
            }
        }
       }
       return ans;
    }
};