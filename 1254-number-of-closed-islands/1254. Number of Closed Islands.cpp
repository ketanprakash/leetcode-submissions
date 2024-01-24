class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        if (grid.size() == 0) return 0; 
        int n = grid.size(), m = grid[0].size(); 
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if ((i == 0 || j == 0 || i == n - 1 || j == m - 1) && grid[i][j] == 0) q.push({i, j});
            }
        }

        int row, col, xrow, xcol; 
        int dr[] = {0, 0, -1, 1};
        int dc[] = {-1, 1, 0, 0};
        while (!q.empty()){
            row = q.front().first;
            col = q.front().second;
            q.pop();

            if (grid[row][col] == 1) continue;
            grid[row][col] = 1;

            for (int x = 0; x < 4; x++){
                xrow = row + dr[x];
                xcol = col + dc[x];

                if (xrow < 0 || xrow >= n || xcol < 0 || xcol >= m) continue;
                q.push({xrow, xcol});
            }
        }
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                cout << grid[i][j] << " ";
            }
            cout << endl;
        }

        int count = 0;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (grid[i][j] == 0){
                    q.push({i, j});
                    count++;
                }
                while (!q.empty()){
                    row = q.front().first;
                    col = q.front().second;
                    q.pop();

                    if (grid[row][col] == 1) continue;
                    grid[row][col] = 1;

                    for (int x = 0; x < 4; x++){
                        xrow = row + dr[x];
                        xcol = col + dc[x];

                        if (xrow < 0 || xrow >= n || xcol < 0 || xcol >= m) continue;
                        q.push({xrow, xcol});
                    }
                }
            }
        }

        return count;
    }
};