class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
        if (grid.size() == 0) return 0;
        int n = grid.size(), m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m));
        queue<pair<int, int>> q1;
        queue<pair<pair<int, int>, int>> q2; 
        
        int row, col, xrow, xcol;
        int dr[] = {0, 0, -1, 1};
        int dc[] = {-1, 1, 0, 0};
        for (int i = 0; i < n; i++){
            if (!q1.empty()) break;
            for (int j = 0; j < m; j++){
                if (grid[i][j] == 0) continue;
                if (!q1.empty()) break;

                q1.push({i, j});
            }
        }

        while (!q1.empty()){
            row = q1.front().first;
            col = q1.front().second;
            q1.pop();
            if (vis[row][col]) continue;
            vis[row][col] = 1;

            for (int x = 0; x < 4; x++){
                xrow = row + dr[x];
                xcol = col + dc[x];

                if (xrow < 0 || xrow >= n || xcol < 0 || xcol >= m) continue;

                if (grid[xrow][xcol] == 0) q2.push({{xrow, xcol}, 0});
                if (grid[xrow][xcol] == 1) q1.push({xrow, xcol});
            }
        }

        int count;
        while (!q2.empty()){
            row = q2.front().first.first;
            col = q2.front().first.second;
            count = q2.front().second;
            q2.pop();

            if (vis[row][col]) continue;
            vis[row][col] = 1;

            if (grid[row][col] == 1) return count;

            for (int x = 0; x < 4; x++){
                xrow = row + dr[x];
                xcol = col + dc[x];

                if (xrow < 0 || xrow >= n || xcol < 0 || xcol >= m) continue;

                q2.push({{xrow, xcol}, count + 1});
            }
        }

        return 0;
    }
};