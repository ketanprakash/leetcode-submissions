class Solution {
public:
    bool helper(int node, vector<vector<int>> &graph, vector<bool> &hasApple, int &ans, vector<bool> &vis){
        int childAns; 
        bool apple = hasApple[node];

        for (int child : graph[node]){
            if (!vis[child]){
                vis[child] = true;
                childAns = 0; 
                if (helper(child, graph, hasApple, childAns, vis)){
                    apple = true;
                    ans += childAns + 2;
                }
            }
        }
        
        return apple;
    }

    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> graph(n); 
        vector<bool> vis(n);

        for (int i = 0; i < edges.size(); i++){
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }

        int ans = 0;
        vis[0] = true;
        if (helper(0, graph, hasApple, ans, vis)){
            return ans;
        }

        return 0;
    }
};