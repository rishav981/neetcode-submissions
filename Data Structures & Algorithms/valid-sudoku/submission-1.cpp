class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = 9;
        unordered_map<int, unordered_set<char>>row,col;
        map<pair<int,int>, unordered_set<char>>square;

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(board[i][j] == '.'){
                    continue;
                }
                if(row[i].count(board[i][j]) || col[j].count(board[i][j]) || square[{i/3,j/3}].count(board[i][j])){
                    return false;
                }
                row[i].insert(board[i][j]);
                col[j].insert(board[i][j]);
                square[{i/3,j/3}].insert(board[i][j]);
            }
        }
        return true;
    }
};
