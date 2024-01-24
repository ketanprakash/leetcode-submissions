class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.size() == 0) return;
        int n = board.size(), m = board[0].size();
        queue<pair<int, int>> q; 

        for (int i = 0; i < n; i++){
            if (board[i][0] == 'O') q.push({i, 0});
            if (board[i][m - 1] == 'O') q.push({i, m - 1});
        }
        for (int j = 0; j < m; j++){
            if (board[0][j] == 'O') q.push({0, j});
            if (board[n - 1][j] == 'O') q.push({n - 1, j});
        }

        int row, col, xrow, xcol; 
        int dc[] = {0, 0, -1, 1};
        int dr[] = {1, -1, 0, 0};

        while (!q.empty()){
            row = q.front().first;
            col = q.front().second;
            q.pop();
            if (board[row][col] == '0') continue;
            board[row][col] = '0';
            
            for (int x = 0; x < 4; x++){
                xrow = row + dr[x];
                xcol = col + dc[x];
                
                if (xrow < 0 || xrow >= n || xcol < 0 || xcol >= m || board[xrow][xcol] == 'X') continue;
                q.push({xrow, xcol});
            }
        }

        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (board[i][j] == '0') board[i][j] = 'O';
                else board[i][j] = 'X';
            }
        }
    }
};