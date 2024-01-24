class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        if (mat.size() == 0) return mat;
        int n = mat.size(), m = mat[0].size();

        vector<vector<int>> dist(n, vector<int>(m, -1));
        queue<pair<int, int>> q; 

        
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (mat[i][j] == 0) {
                    q.push({i, j});
                    dist[i][j] = 0;
                }
            }
        }

        vector<int> dx{0, 0, -1, 1};
        vector<int> dy{1, -1, 0, 0};

        while (!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++){
                int nx = row + dx[i];
                int ny = col + dy[i];

                if (nx < 0 || nx >= n || ny < 0 || ny >= m || dist[nx][ny] != -1) continue;
                dist[nx][ny] = dist[row][col] + 1;
                q.push({nx, ny});
            }
        }

        return dist;
    }
};