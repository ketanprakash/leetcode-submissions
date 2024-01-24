class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string, double>>> graph; 

        string u, v, node; 
        double wt; 
        for (int i = 0; i < equations.size(); i++){
            u = equations[i][0], v = equations[i][1], wt = values[i];
            graph[u].push_back({v, wt});
            graph[v].push_back({u, 1 / wt});
        }

        queue<pair<string, double>> q;
        vector<double> ans(queries.size(), -1);
        double dst; 

        for (int i = 0; i < queries.size(); i++){
            u = queries[i][0], v = queries[i][1];
            unordered_map<string, bool> vis; 

            for (auto p : graph) vis[p.first] = false;

            if (graph.count(u) && graph.count(v)){
                q = queue<pair<string, double>>();
                q.push({u, 1});

                while (!q.empty()){
                    node = q.front().first;
                    dst = q.front().second;
                    q.pop();

                    if (vis[node]) continue; 
                    vis[node] = true;

                    if (node == v) {
                        ans[i] = dst;
                        break;
                    }

                    for (auto p : graph[node]){
                        string child = p.first;
                        wt = p.second; 

                        q.push({child, dst * wt});
                    }
                }
            }
        }

        return ans;
    }
};