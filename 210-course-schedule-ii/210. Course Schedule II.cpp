class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& edges) {
        vector<int> ans; 
        vector<int> indegree(n);
        vector<vector<int>> graph(n);
        queue<int> q;
        
        int u, v;
        for (int i = 0; i < edges.size(); i++){
            u = edges[i][1], v = edges[i][0];
            graph[u].push_back(v);
            indegree[v]++;
        }

        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()){
            int node = q.front(); 
            q.pop(); 

            ans.push_back(node);

            for (int child : graph[node]){
                if (--indegree[child] == 0){
                    q.push(child);
                }
            }
        }

        return ans.size() == n ? ans : vector<int>();
    }
};