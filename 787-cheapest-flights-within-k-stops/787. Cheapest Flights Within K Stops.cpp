class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dest, int k) {
        vector<int> dist(n, -1);
        dist[src] = 0; 

        vector<vector<pair<int, int>>> graph(n);
        int u, v, wt; 
        for (int i = 0; i < flights.size(); i++){
            u = flights[i][0], v = flights[i][1], wt = flights[i][2];
            graph[u].push_back({v, wt});
        }

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;

        q.push({0, {0, src}});
        while (!q.empty()){
            int stops = q.top().first;
            int dst = q.top().second.first;
            int node = q.top().second.second;
            q.pop();

            for (auto &[child, wt] : graph[node]){
                if ((dist[child] == -1 || dist[child] > dst + wt) && stops <= k){
                    dist[child] = dst + wt; 
                    q.push({stops + 1, {dst + wt, child}});
                }
            }
        }

        return dist[dest];
    }
};