class Solution {
public:
    bool check(vector<vector<char>> &board, int row, int col, char num){
        for (int i = 0; i < 9; i++){
            if (board[row][i] == num || board[i][col] == num) return false;
        }

        int start_row = row / 3 * 3;
        int start_col = col / 3 * 3;

        for (int i = start_row; i < start_row + 3; i++){
            for (int j = start_col; j < start_col + 3; j++){
                if (board[i][j] == num) return false;
            }
        }

        return true;
    }

    bool generateBoard(vector<vector<char>> &board, int row, int col){
        if (col == 9){
            col = 0;
            row++;
        }

        if (row == 9){
            return true;
        }

        if (board[row][col] != '.'){
            if (generateBoard(board, row, col + 1)) return true;
            return false;
        }

        for (int i = 1; i <= 9; i++){
            if (check(board, row, col, '0' + i)){
                board[row][col] = '0' + i;
                if(generateBoard(board, row, col + 1)) return true;
                board[row][col] = '.';
            }
        }

        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        generateBoard(board, 0, 0);
    }
};