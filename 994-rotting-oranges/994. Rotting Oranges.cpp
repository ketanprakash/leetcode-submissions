class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        if (grid.size() == 0) return 0;
        int n = grid.size(), m = grid[0].size();

        queue<pair<pair<int, int>, int>> q; 
        
        int maxTime = 0;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (grid[i][j] == 2){
                    q.push({{i, j}, 0});
                }
            }
        }

        int row, col, time, xrow, xcol;
        int dr[] = {0, 0, -1, 1};
        int dc[] = {1, -1, 0, 0};

        while (!q.empty()){
            row = q.front().first.first;
            col = q.front().first.second;
            time = q.front().second;
            q.pop();

            maxTime = max(time, maxTime);
            for (int x = 0; x < 4; x++){
                xrow = row + dr[x];
                xcol = col + dc[x];

                if (xrow < 0 || xrow >= n || xcol < 0 || xcol >= m || grid[xrow][xcol] == 0 || grid[xrow][xcol] == 2) continue;
                grid[xrow][xcol] = 2;
                q.push({{xrow, xcol}, time + 1});
            }
        }

        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (grid[i][j] == 1) return -1;
            }
        }
        return maxTime;
    }
};