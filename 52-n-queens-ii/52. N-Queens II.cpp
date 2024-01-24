class Solution {
public:
    bool check(vector<string> &board, int idx, int i){
        for (int j = 0; j < idx; j++){
            if (board[j][i] == 'Q') return false;
        }

        for (int j = 0; j < i; j++){
            if (board[idx][j] == 'Q') return false;
        }

        int row = idx - 1, col = i - 1; 
        while (row >= 0 && col >= 0){
            if (board[row][col] == 'Q') return false;
            row--; col--;
        }
        
        row = idx - 1, col = i + 1;
        while (row >= 0 && col < board.size()){
            if (board[row][col] == 'Q') return false;
            row--; col++;
        }

        return true;
    }

    void solveNQueens(vector<string> &board, int idx, vector<vector<string>> &ans){
        if (idx == board.size()){
            ans.push_back(board);
            return;
        }

        for (int i = 0; i < board[idx].size(); i++){
            if (check(board, idx, i)){
                board[idx][i] = 'Q';
                solveNQueens(board, idx + 1, ans);
                board[idx][i] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        string str; 
        for (int i = 0; i < n; i++) str.push_back('.');
        vector<string> board;
        for (int i = 0; i < n; i++) board.push_back(str);
        vector<vector<string>> ans;
        solveNQueens(board, 0, ans);

        return ans;
    }

    int totalNQueens(int n) {
        vector<vector<string>> ans = solveNQueens(n);
        return ans.size();
    }
};