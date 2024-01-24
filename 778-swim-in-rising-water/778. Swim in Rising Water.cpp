class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        if (grid.size() == 0) return 0;
        int n = grid.size();
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;
        vector<vector<int>> vis(n, vector<int>(n));
        
        int t = 0;

        q.push({grid[0][0], {0, 0}});

        int dx[] = {0, 0, -1, 1};
        int dy[] = {1, -1, 0, 0};

        while (!q.empty()){
            int wt = q.top().first;
            int row = q.top().second.first;
            int col = q.top().second.second;
            q.pop();
            
            if (vis[row][col]) continue;

            t += wt;
            if (row == n - 1 && col == n - 1) return t;

            for (int i = 0; i < 4; i++){
                int nx = row + dx[i];
                int ny = col + dy[i];

                if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;

                q.push({t >= grid[nx][ny] ? 0 : grid[nx][ny] - t, {nx, ny}});
            }
            vis[row][col] = 1;
        }

        return 0;
    }
};