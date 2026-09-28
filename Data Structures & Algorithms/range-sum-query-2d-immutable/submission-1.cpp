class NumMatrix {
public:
 vector<vector<int>> matrix;
    NumMatrix(vector<vector<int>>& matrix) {
        this->matrix = matrix;
        int n = matrix.size();
        int m = matrix[0].size();

        for(int j = 1; j < m; j++){
    this->matrix[0][j] += this->matrix[0][j-1];
        }

        for(int i = 1; i < n; i++){
    this->matrix[i][0] += this->matrix[i-1][0];
        }

        for(int i=1; i<n; i++){
            for(int j=1; j<m; j++){
               this->matrix[i][j] =
   this->matrix[i][j]
    + this->matrix[i-1][j]
    + this->matrix[i][j-1]
    - this->matrix[i-1][j-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sub1 = 0;
        int sub2 = 0;
        int add = 0;
        if(row1>0){
        sub1 = matrix[row1-1][col2];
        }
        if(col1>0){
            sub2 = matrix[row2][col1-1];
        }
         if(col1>0 && row1>0){
            add = matrix[row1-1][col1-1];
         }

         return matrix[row2][col2]-sub1-sub2+add;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */