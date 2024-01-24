class Solution {
public:
    bool dfs(vector<vector<char>> &board, string &word, int i, int j, vector<vector<bool>> &vis){
        if (word.size() ==  0) return true;

        int dr[] = {0, 0, -1, 1};
        int dc[] = {-1, 1, 0, 0};

        for (int x = 0; x < 4; x++){
            int row = i + dr[x], col = j + dc[x];
            if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size()) continue;
            if (!vis[row][col] && word.back() == board[row][col]){
                vis[row][col] = true;
                word.pop_back();
                if (dfs(board, word, row, col, vis)) return true;
                word.push_back(board[row][col]);
                vis[row][col] = false;
            }
        }

        return false;
    }
    bool exist(vector<vector<char>>& board, string &word) {
        vector<vector<bool>> vis(board.size(), vector<bool>(board[0].size()));
        for (int i = 0; i < board.size(); i++){
            for (int j = 0; j < board[i].size(); j++){
                if (word.back() == board[i][j]){
                    vis[i][j] = true;
                    word.pop_back();
                    if (dfs(board, word, i, j, vis)) return true;
                    word.push_back(board[i][j]);
                    vis[i][j] = false;
                }
            }
        }

        return false;
    }
};