class Solution {
public:
bool isvalid(vector<vector<char>>& board, int row,int col, char digit){
    for(int i=0;i<9;i++){
            if(board[i][col]==digit){
                return false;
            }
        }
    for(int j=0;j<9;j++){
        if(board[row][j]==digit){
            return false;
        }
    }

  int startr=(row/3)*3;
  int startc=(col/3)*3;
  for(int i= startr;i<startr+3;i++){
    for(int j=startc;j<startc+3;j++){
        if(board[i][j]==digit){
            return false;
        }
    }
  }
  return true;

}
bool solve(vector<vector<char>>& board){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(board[i][j]=='.'){
                for(char digit ='1';digit<='9';digit++){
                    if(isvalid(board,i,j,digit)){
board[i][j]=digit;
if(solve(board)){
    return true;
}
board[i][j]='.';
                    }
                }
                return false;
            }
        }
    }
    return true;
}
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};