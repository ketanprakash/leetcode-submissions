class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        if (heights.size() == 0) return 0;
        int n = heights.size(), m = heights[0].size();

        vector<vector<int>> dist(n, vector<int>(m, -1));
        dist[0][0] = 0;

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q; 

        q.push({0, {0, 0}});

        int dr[] = {0, 0, -1, 1};
        int dc[] = {1, -1, 0, 0};
        int row, col, dst, xrow, xcol, wt;
        while (!q.empty()){
            row = q.top().second.first;
            col = q.top().second.second;
            dst = q.top().first;
            q.pop();
            
            for (int x = 0; x < 4; x++){
                xrow = row + dr[x];
                xcol = col + dc[x];
                
                if (xrow < 0 || xrow >= n || xcol < 0 || xcol >= m) continue;
                
                wt = abs(heights[row][col] - heights[xrow][xcol]);
                if (dist[xrow][xcol] == -1 || dist[xrow][xcol] > max(wt, dst)){
                    dist[xrow][xcol] = max(wt, dst);
                    q.push({dist[xrow][xcol], {xrow, xcol}});
                }
            }
        }

        return dist[n - 1][m - 1];
    }
};