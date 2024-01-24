class Solution {
public:
    void findSafe(int node, vector<vector<int>> &graph, vector<int> &vis, vector<int> &safe){
        if (vis[node]) return;
        vis[node] = 1;

        safe[node] = false; 

        for (int child : graph[node]){
            findSafe(child, graph, vis, safe);

            if (!safe[child]) {
                safe[node] = false;
                return;
            }
        }

        safe[node] = true;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> vis(graph.size());
        vector<int> safe(graph.size());
        vector<int> ans;

        for (int i = 0; i < graph.size(); i++){
            findSafe(i, graph, vis, safe);
        }

        for (int i = 0; i < graph.size(); i++){
            if (safe[i]) ans.push_back(i);
        }

        return ans;
    }
};