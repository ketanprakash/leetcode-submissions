class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int count = 0;
        if (grid.size() == 0) return count;
        int n = grid.size(), m = grid[0].size();
        stack<pair<int, int>> st;

        for (int i = 0; i < n; i++){
            if (grid[i][0] == 1) {
                grid[i][0] = 2;
                st.push({i, 0});
            }
            if (grid[i][m - 1] == 1){
                grid[i][m - 1] = 2;
                st.push({i, m - 1});
            }
        }

        for (int j = 0; j < m; j++){
            if (grid[0][j] == 1) {
                grid[0][j] = 2;
                st.push({0, j});
            }
            if (grid[n - 1][j] == 1){
                grid[n - 1][j] = 2;
                st.push({n - 1, j});
            }
        }

        vector<int> dx{0, 0, 1, -1};
        vector<int> dy{1, -1, 0, 0};

        while (!st.empty()){
            int row = st.top().first;
            int col = st.top().second;
            st.pop();

            for (int i = 0; i < 4; i++){
                int nx = row + dx[i], ny = col + dy[i];

                if (nx < 0 || nx >= n || ny < 0 || ny >= m || grid[nx][ny] != 1) continue;

                grid[nx][ny] = 2;
                st.push({nx, ny});
            }
        }

        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (grid[i][j] == 1) count++;
            }
        }

        return count;
    }
};