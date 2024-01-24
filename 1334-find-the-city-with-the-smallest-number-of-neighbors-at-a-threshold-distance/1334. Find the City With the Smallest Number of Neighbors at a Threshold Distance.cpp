class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n, vector<int>(n, -1));

        for (int i = 0; i < n; i++) dist[i][i] = 0;
        for (int i = 0; i < edges.size(); i++){
            int u = edges[i][0], v = edges[i][1], wt = edges[i][2];
            dist[u][v] = wt;
            dist[v][u] = wt;
        }

        for (int via = 0; via < n; via++){
            for (int i = 0; i < n; i++){
                for (int j = 0; j < n; j++){
                    if (dist[i][via] == -1 || dist[via][j] == -1) continue;
                    dist[i][j] = dist[i][j] == -1 ? dist[i][via] + dist[via][j] : min(dist[i][via] + dist[via][j], dist[i][j]);
                }
            }
        }

        int minCount = INT_MAX;
        int minCity = -1;

        for (int i = 0; i < n; i++){
            int count = 0;
            for (int j = 0; j < n; j++){
                if (dist[i][j] <= distanceThreshold){
                    count++;
                }
            }
            if (minCount >= count){
                minCity = i;
                minCount = count;
            }
        }

        return minCity;
    }
};