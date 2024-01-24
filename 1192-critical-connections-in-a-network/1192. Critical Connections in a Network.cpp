class Solution {
public:
    void dfs(vector<int> graph[], int node, int parent, int &timer, vector<int> &vis, vector<int> &tin, vector<int> &low, vector<vector<int>> &ans){
        tin[node] = low[node] = timer++;

        for (int child : graph[node]){
            if (child == parent) continue;
            if (!vis[child]){
                vis[child] = 1;
                dfs(graph, child, node, timer, vis, tin, low, ans);
                low[node] = min(low[child], low[node]);
                if (low[child] > tin[node]) ans.push_back({node, child});
            }
            else {
                low[node] = min(low[child], low[node]);
            }
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> graph[n];
        for (int i = 0; i < connections.size(); i++){
            int u = connections[i][0];
            int v = connections[i][1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        int timer = 0;
        vector<int> tin(n);
        vector<int> low(n);
        vector<int> vis(n);
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++){
            if (!vis[i]){
                vis[i] = 1;
                dfs(graph, i, -1, timer, vis, tin, low, ans);
            }
        }

        return ans;
    }
};