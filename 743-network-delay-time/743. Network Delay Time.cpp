class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dist(n, -1);
        dist[k - 1] = 0; 

        int u, v, wt; 
        vector<vector<pair<int, int>>> graph(n);
        for (int i = 0; i < times.size(); i++){
            u = times[i][0] - 1; v = times[i][1] - 1; wt = times[i][2];
            graph[u].push_back({v, wt});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q; 

        q.push({0, k - 1});

        while (!q.empty()){
            int dst = q.top().first;
            int node = q.top().second;
            q.pop();

            for (auto &[child, wt] : graph[node]){
                if (dist[child] == -1 || dist[child] > dst + wt){
                    dist[child] = dst + wt;
                    q.push({dst + wt, child});
                }
            }
        }

        int ans = -1; 
        for (int i = 0; i < dist.size(); i++){
            if (dist[i] == -1) return -1;
            ans = max(ans, dist[i]);
        }

        return ans;
    }
};