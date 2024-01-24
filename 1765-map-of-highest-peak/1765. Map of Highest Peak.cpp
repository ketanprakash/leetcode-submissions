class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        if (isWater.size() == 0) return {};

        int n = isWater.size(); 
        int m = isWater[0].size();
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (isWater[i][j]) isWater[i][j] = 0;
                else isWater[i][j] = 1e6;
            }
        }

        queue<pair<pair<int, int>, int>> q;

        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (isWater[i][j] == 0) q.push({{i, j}, 0});
            }
        }

        int dr[] = {0, 0, -1, 1};
        int dc[] = {1, -1, 0, 0};

        while (!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int dist = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++){
                int x = row + dr[i], y = col + dc[i];

                if (x < 0 || x >= n || y < 0 || y >= m || isWater[x][y] == 0) continue;
                if (dist + 1 < isWater[x][y]){
                    isWater[x][y] = dist + 1;
                    q.push({{x, y}, isWater[x][y]});
                }
            }
        }

        return isWater;
    }
};