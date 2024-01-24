class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int, double>>> graph(n);

        int u, v; 
        double wt;
        for (int i = 0; i < edges.size(); i++){
            u = edges[i][0], v = edges[i][1], wt = succProb[i];
            graph[u].push_back({v, wt});
            graph[v].push_back({u, wt});
        }

        vector<double> dist(n);
        dist[start_node] = 1;
        priority_queue<pair<double, int>> q;

        q.push({1, start_node});

        int node;
        double dst;
        while (!q.empty()){
            dst = q.top().first;
            node = q.top().second;
            q.pop();

            for (auto &[child, wt] : graph[node]){
                if (dist[child] < dst * wt){
                    dist[child] = dst * wt;
                    q.push({dist[child], child});
                }
            }
        }

        return dist[end_node];
    }
};