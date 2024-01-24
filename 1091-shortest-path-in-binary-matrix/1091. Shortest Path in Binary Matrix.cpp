class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size(); 
        queue<pair<pair<int, int>, int>> q; 
        if (grid[0][0] == 1) return -1;
        q.push({{0, 0}, 1});
        
        int row, col, xrow, xcol, length;
        vector<vector<int>> vis(n, vector<int>(n));

        while (!q.empty()){
            row = q.front().first.first;
            col = q.front().first.second;
            length = q.front().second;
            q.pop();

            if (row == n - 1 && col == n - 1) return length;
            if (vis[row][col]) continue;
            vis[row][col] = 1;

            for (int dr = -1; dr <= 1; dr++){
                for (int dc = -1; dc <= 1; dc++){
                    xrow = row + dr;
                    xcol = col + dc;

                    if (xrow < 0 || xrow >= n || xcol < 0 || xcol >= n || grid[xrow][xcol] == 1) continue;
                    q.push({{xrow, xcol}, length + 1});
                }
            }
        }

        return -1;
    }
};