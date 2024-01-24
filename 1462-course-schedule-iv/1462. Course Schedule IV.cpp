class Solution {
public:
    void findprereqs(int node, vector<vector<int>> &graph, vector<unordered_set<int>> &prereqs, vector<int> &vis){
        if (vis[node]) return;
        vis[node] = 1; 

        for (int child : graph[node]){
            findprereqs(child, graph, prereqs, vis);
            prereqs[node].insert(child);
            for (int p : prereqs[child]){
                prereqs[node].insert(p);
            }
        }
    }

    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        vector<unordered_set<int>> prereqs(n);
        vector<vector<int>> graph(n);

        int u, v;
        for (int i = 0; i < edges.size(); i++){
            u = edges[i][0], v = edges[i][1];
            graph[u].push_back(v);
        }
        vector<int> vis(n);

        for (int i = 0; i < n; i++){
            findprereqs(i, graph, prereqs, vis);
        }

        vector<bool> ans;
        for (int i = 0; i < queries.size(); i++){
            u = queries[i][0], v = queries[i][1];
            ans.push_back(prereqs[u].count(v));
        }

        return ans;
    }
};