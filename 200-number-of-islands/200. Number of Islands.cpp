class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.size() == 0) return 0;
        int ans = 0; 
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m));
        queue<pair<int, int>> q;

        int dc[] = {0, 0, 1, -1};
        int dr[] = {1, -1, 0, 0};
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (vis[i][j] || grid[i][j] == '0') continue;
                vis[i][j] = true;
                ans++;
                q.push({i, j});

                while (!q.empty()){
                    int row = q.front().first; 
                    int col = q.front().second; 
                    q.pop();

                    for (int x = 0; x < 4; x++){
                        int childRow = row + dr[x], childCol = col + dc[x];
                        if (childRow < 0 || childRow >= n || childCol < 0 || childCol >= m || grid[childRow][childCol] == '0' || vis[childRow][childCol]) continue;
                        vis[childRow][childCol] = true;
                        q.push({childRow, childCol});
                    }
                }
            }
        }

        return ans;
    }
};