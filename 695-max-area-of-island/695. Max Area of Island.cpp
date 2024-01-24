class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if (grid.size() == 0) return 0;
        int n = grid.size(), m = grid[0].size(); 
        vector<vector<int>> vis(n, vector<int>(m));
        
        queue<pair<int, int>> q; 
        int dr[] = {0, 0, 1, -1};
        int dc[] = {-1, 1, 0, 0};
        int maxArea = 0, area = 0, row, col;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (grid[i][j] == 0) continue;
                if (vis[i][j] != 0) continue;
                vis[i][j] = 1;
                area = 0; 
                q.push({i, j});

                while (!q.empty()){
                    row = q.front().first; 
                    col = q.front().second; 
                    q.pop(); 
                    area++;

                    for (int x = 0; x < 4; x++){
                        row += dr[x];
                        col += dc[x];

                        if (row < 0 || row >= n || col < 0 || col >= m || grid[row][col] == 0 || vis[row][col]){
                            row -= dr[x];
                            col -= dc[x];
                            continue;
                        }
                        vis[row][col] = 1; 
                        q.push({row, col});
                        row -= dr[x];
                        col -= dc[x];
                    }
                }
                maxArea = max(area, maxArea);
            }
        } 

        return maxArea;       
    }
};