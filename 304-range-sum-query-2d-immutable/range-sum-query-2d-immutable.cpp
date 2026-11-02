class NumMatrix {
public:
    vector<vector<int>> p;  // Class member

    NumMatrix(vector<vector<int>>& matrix) {
        int m= matrix.size();
        int n= matrix[0].size();
      p =  vector<vector<int>> (
    m + 1,
    vector<int>(n + 1, 0)
); 
for(int i = 0; i < m; i++) {
    for(int j = 0; j < n; j++) {
        p[i+1][j+1] = matrix[i][j]
                    + p[i][j+1]
                    + p[i+1][j]
                    - p[i][j];
    }
}
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int total = p[row2+1][col2+1]
              - p[row1][col2+1]
              - p[row2+1][col1]
              + p[row1][col1];

    return total;  
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */