class Solution {
public:
int n;
int count;
vector<string>board;
bool isSafe(int row,int col){
    for(int i=0;i<row;i++){
        if(board[i][col]=='Q'){
            return false;
        }
    }

for(int i=row-1,j=col-1; i>=0 && j>=0 ; i--,j--){
    if(board[i][j]=='Q'){
        return false;
    }
}

for(int i=row-1,j=col+1;i>=0 && j<n; i--,j++){
    if(board[i][j]=='Q'){
        return false;
    }
}
return true;
}

void solve(int row){
    if(row==n){
        count++;
        return;
    }

    for(int col=0;col<n;col++){
        if(isSafe(row,col)){
            board[row][col]='Q';
            solve(row+1);
            board[row][col]='.';
        }
    }

}
    int totalNQueens(int n) {
        this->n=n;
        count=0;
        board=vector<string>(n, string(n, '.'));
        solve(0);
        return count;
    }
};