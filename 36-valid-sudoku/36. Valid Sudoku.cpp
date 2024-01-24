class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> s;
        for (int i = 0; i < 9; i++){
            s.clear();
            for (int j = 0; j < 9; j++){
                if (board[i][j] == '.') continue;
                if (s.count(board[i][j]) == 1) {
                    return false;
                }
                s.insert(board[i][j]);
            }
        }

        for (int i = 0; i < 9; i++){
            s.clear();
            for (int j = 0; j < 9; j++){
                if (board[j][i] == '.') continue;
                if (s.count(board[j][i]) == 1){
                    return false;
                }
                s.insert(board[j][i]);
            }
        }

        for (int x = 0; x < 9; x += 3){
            for (int y = 0; y < 9; y += 3){
                s.clear();
                for (int i = x; i < x + 3; i++){
                    for (int j = y; j < y + 3; j++){
                        if (board[i][j] == '.') continue;
                        if (s.count(board[i][j]) == 1) {
                            return false;
                        }
                        s.insert(board[i][j]);
                    }
                }
            }
        }

        return true;
    }
};