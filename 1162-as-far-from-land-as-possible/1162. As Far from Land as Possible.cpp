class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        if (grid.size() == 0) return 0; 
        int n = grid.size(), m = grid[0].size();

        vector<vector<int>> dist(n, vector<int>(m, -1));

        queue<pair<pair<int, int>, int>> q; 

        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (grid[i][j] == 1){
                    dist[i][j] = 0;
                    q.push({{i, j}, 0});
                }
            }
        }

        int row, col, xrow, xcol, dst; 
        int dr[] = {0, 0, -1, 1};
        int dc[] = {-1, 1, 0, 0};
        while (!q.empty()){
            row = q.front().first.first; 
            col = q.front().first.second; 
            dst = q.front().second;
            q.pop(); 

            for (int x = 0; x < 4; x++){
                xrow = row + dr[x];
                xcol = col + dc[x];

                if (xrow < 0 || xrow >= n || xcol < 0 || xcol >= m) continue;

                if (dist[xrow][xcol] == -1 || dist[xrow][xcol] > dst + 1){
                    dist[xrow][xcol] = dst + 1;
                    q.push({{xrow, xcol}, dist[xrow][xcol]});
                }
            }
        }

        int ans = -1; 
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (dist[i][j] != 0){
                    ans = max(ans, dist[i][j]);
                }
            }
        }

        return ans;
    }
};