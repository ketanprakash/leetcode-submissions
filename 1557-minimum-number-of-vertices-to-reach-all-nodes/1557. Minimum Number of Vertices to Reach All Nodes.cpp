class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> indegree(n); 
        vector<vector<int>> graph(n);

        int u, v;
        for (int i = 0; i < edges.size(); i++){
            u = edges[i][0], v = edges[i][1];
            indegree[v]++;
            graph[u].push_back(v);
        }

        vector<int> ans;

        queue<int> q;
        for (int i = 0; i < n; i++){
            if (indegree[i] == 0){
                ans.push_back(i);
            }
        }
        
        return ans;
    }
};