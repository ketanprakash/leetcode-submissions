class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size(); 
        vector<vector<int>> graph(n);

        int u, v;
        vector<int> indegree(n);
        for (int i = 0; i < edges.size(); i++){
            u = edges[i][0], v = edges[i][1];
            graph[u].push_back(v);
            indegree[v]++;
        }
    
        vector<int> topoSort;
        queue<int> q;
        for (int i = 0; i < n; i++){
            if (indegree[i] == 0) q.push(i);
        }

        while (!q.empty()){
            int node = q.front(); 
            q.pop(); 

            topoSort.push_back(node);

            for (int child : graph[node]){
                if (--indegree[child] == 0) q.push(child);
            }
        }

        if (topoSort.size() != n) return -1;

        reverse(topoSort.begin(), topoSort.end());

        vector<vector<int>> maxColors(n, vector<int>(26));
        int ans = 0;
        for (int node : topoSort){
            for (int child : graph[node]){
                for (int i = 0; i < 26; i++){
                    maxColors[node][i] = max(maxColors[node][i], maxColors[child][i]);
                }
            }
            maxColors[node][colors[node] - 'a']++;
            ans = max(maxColors[node][colors[node] - 'a'], ans);
        }

        return ans;
    }
};