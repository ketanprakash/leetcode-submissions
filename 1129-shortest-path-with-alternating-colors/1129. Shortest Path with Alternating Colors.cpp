class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<vector<int>>> graph(n, vector<vector<int>>(2));
        vector<vector<int>> dist(2, vector<int>(n, -1));
        
        int u, v;
        for (int i = 0; i < redEdges.size(); i++){
            u = redEdges[i][0]; v = redEdges[i][1];
            graph[u][0].push_back(v);
            cout << u << " " << v << " " << 0 << endl;
        }

        for (int i = 0; i < blueEdges.size(); i++){
            u = blueEdges[i][0]; v = blueEdges[i][1];
            graph[u][1].push_back(v);
        }

        queue<pair<pair<int, int>, int>> q; 
        q.push({{0, 0}, 0});
        q.push({{0, 1}, 0});
        dist[0][0] = 0; dist[1][0] = 0;

        int node, color, dst;
        while (!q.empty()){
            node = q.front().first.first;
            color = q.front().first.second;
            dst = q.front().second;
            q.pop();
            for (int child : graph[node][!color]){
                if (dist[!color][child] == -1 || dist[!color][child] > dst + 1){
                    dist[!color][child] = dst + 1;
                    q.push({{child, !color}, dst + 1});
                }        
            }
        }

        for (int i = 0; i < n; i++){
            if (dist[0][i] == -1) dist[0][i] = dist[1][i];
            else if (dist[1][i] == -1) dist[0][i] = dist[0][i];
            else dist[0][i] = min(dist[0][i], dist[1][i]);
        }

        return dist[0];
    }
};