class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>> graph(n), revGraph(n); 

        int u, v;
        for (int i = 0; i < connections.size(); i++){
            u = connections[i][0], v = connections[i][1];
            graph[u].push_back(v);
            revGraph[v].push_back(u);
        }

        vector<int> vis(n);
        queue<int> q; 

        vis[0] = 1;
        q.push(0);
        int ans = 0;
        while (!q.empty()){
            int node = q.front(); 
            q.pop();

            for (int child : graph[node]){
                if (vis[child]) continue;
                ans++;
                vis[child] = 1;
                q.push(child);
            }

            for (int child : revGraph[node]){
                if (vis[child]) continue;
                vis[child] = 1;
                q.push(child);
            }
        }

        return ans;
    }
};