class Solution {
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        if (grid1.size() == 0) return 0;
        int n = grid1.size(), m = grid1[0].size(); 

        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (grid1[i][j] == 1 && grid2[i][j] == 1) grid2[i][j] = 2;
            }
        }

        vector<vector<int>> vis(n, vector<int>(m));
        queue<pair<int, int>> q; 
        int ans = 0;
        int row, col;
        int dc[] = {0, 0, -1, 1};
        int dr[] = {1, -1, 0, 0};

        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (vis[i][j]) continue;
                if (grid2[i][j] == 0) continue;
                vis[i][j] = 1;
                q.push({i, j});
                bool flag = true;
                while (!q.empty()){
                    row = q.front().first; 
                    col = q.front().second; 
                    q.pop(); 
                    if (grid2[row][col] == 1) flag = false;

                    for (int x = 0; x < 4; x++){
                        row += dr[x];
                        col += dc[x];

                        if (row < 0 || row >= n || col < 0 || col >= m || grid2[row][col] == 0 || vis[row][col]) {
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
                if (flag) ans++;
            }
        }

        return ans;
    }
};