class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        if (heights.size() == 0) return {};
        int n = heights.size(), m = heights[0].size();
        queue<pair<int, int>> q1;
        vector<vector<int>> atlantic(n, vector<int>(m)), pacific(n, vector<int>(m));
        vector<vector<int>> ans;
        int row, col, xrow, xcol;
        int dr[] = {0, 0, -1, 1};
        int dc[] = {-1, 1, 0, 0};

        for (int i = 0; i < n; i++){
            pacific[i][0] = 1;
            q1.push({i, 0});
        }

        for (int j = 0; j < m; j++){
            pacific[0][j] = 1;
            q1.push({0, j});
        }

        while (!q1.empty()){
            row = q1.front().first;
            col = q1.front().second;
            q1.pop();

            for (int i = 0; i < 4; i++){
                xrow = row + dr[i];
                xcol = col + dc[i];

                if (xrow < 0 || xrow >= n || xcol < 0 || xcol >= m || pacific[xrow][xcol] || heights[xrow][xcol] < heights[row][col]) continue;
                pacific[xrow][xcol] = 1;
                q1.push({xrow, xcol});
            }
        }

        for (int i = 0; i < n; i++){
            atlantic[i][m - 1] = 1;
            q1.push({i, m - 1});
        }

        for (int j = 0; j < m; j++){
            atlantic[n - 1][j] = 1;
            q1.push({n - 1, j});
        }

        while (!q1.empty()){
            row = q1.front().first;
            col = q1.front().second;
            q1.pop();

            for (int i = 0; i < 4; i++){
                xrow = row + dr[i];
                xcol = col + dc[i];

                if (xrow < 0 || xrow >= n || xcol < 0 || xcol >= m || atlantic[xrow][xcol] || heights[xrow][xcol] < heights[row][col]) continue;
                atlantic[xrow][xcol] = 1;
                q1.push({xrow, xcol});
            }
        }

        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (atlantic[i][j] && pacific[i][j]) ans.push_back({i, j});
            }
        }

        return ans;
    }
};