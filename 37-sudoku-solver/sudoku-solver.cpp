class Solution {
public:
bool isvalid(vector<vector<char>>& board, int row,int col, char digit){
    for(int i=0;i<9;i++){//column mein us digit ki validy check 
            if(board[i][col]==digit){
                return false;
            }
        }
    for(int j=0;j<9;j++){//row mein cell ki validity check 
        if(board[row][j]==digit){
            return false;
        }
    }
// jis bhi position pe agar ho uske ek piece of 3*3 square  manlo and waha se check kro ki kya yeh digit kahoi us square mein toh nhi aaya hai 
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
            if(board[i][j]=='.'){//empty hona chaiye woh cell
                for(char digit ='1';digit<='9';digit++){//agar empty hai toh us cell mein digit 1 se 9 tk hr value chaeck kro valid ho toh woh number us cell komassign krdo 
                    if(isvalid(board,i,j,digit)){//!checking validity of the digit
board[i][j]=digit;//valid digit cell ko assign
if(solve(board)){//recusrion se next step ya next cell pe kaam 
    return true;
}
board[i][j]='.';//backtracking 
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