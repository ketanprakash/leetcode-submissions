class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        if (grid.size() == 0) return 0;

        int n = grid.size(), m = grid[0].size(); 
        int ans = 0;
        int dr[] = {0, 0, -1, 1};
        int dc[] = {1, -1, 0, 0};

        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (grid[i][j] == 0) continue;

                for (int x = 0; x < 4; x++){
                    int r = i + dr[x], c = j + dc[x];

                    if (r < 0 || r >= n || c < 0 || c >= m || grid[r][c] == 0) ans++;
                }
            }
        }

        return ans;
    }
};