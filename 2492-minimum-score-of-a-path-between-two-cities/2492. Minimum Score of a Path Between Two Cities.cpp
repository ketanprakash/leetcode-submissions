class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> graph(n + 1);

        int u, v, wt;
        for (int i = 0; i < roads.size(); i++){
            u = roads[i][0], v = roads[i][1], wt = roads[i][2];
            graph[u].push_back({v, wt});
            graph[v].push_back({u, wt});
        }

        vector<int> dist(n + 1, -1); 
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q; 

        for (auto p : graph[1]){
            int child = p.first;
            int wt = p.second;

            dist[child] = wt; 
            q.push({wt, child});
        }

        while (!q.empty()){
            int node = q.top().second;
            int dst = q.top().first;
            q.pop(); 

            for (auto p : graph[node]){
                int child = p.first;
                int wt = p.second; 

                if (dist[child] == -1 || dist[child] > min(dst, wt)){
                    dist[child] = min(dst, wt);
                    q.push({dist[child], child});
                }
            }
        }

        return dist[n];
    }
};