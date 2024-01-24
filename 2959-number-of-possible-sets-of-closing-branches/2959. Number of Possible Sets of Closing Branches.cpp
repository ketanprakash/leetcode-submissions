class Solution {
public:
    bool check(vector<int> &included, vector<vector<int>> &roads, int maxDistance){
        unordered_map<int, int> m;
        int n = included.size();
        vector<vector<int>> dist(n, vector<int>(n, -1));
        
        for (int i = 0; i < n; i++){
            m[included[i]] = i;
            dist[i][i] = 0;
        }
        
        for (int i = 0; i < roads.size(); i++){
            int u = roads[i][0], v = roads[i][1], wt = roads[i][2];
            if (m.count(u) && m.count(v)){
                u = m[u], v = m[v];
                dist[u][v] = dist[u][v] == -1 ? wt : min(wt, dist[u][v]);
                dist[v][u] = dist[v][u] == -1 ? wt : min(wt, dist[v][u]);
            }
        }
        
        for (int k = 0; k < n; k++){
            for (int i = 0; i < n; i++){
                for (int j = 0; j < n; j++){
                    if (dist[i][k] != -1 && dist[k][j] != -1){
                        dist[i][j] = dist[i][j] == -1 ? dist[i][k] + dist[k][j] : min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }
        
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if (dist[i][j] == -1 || dist[i][j] > maxDistance) return false;
            }
        }
        
        return true;
    }
    
    void helper(int n, int idx, vector<int> &included, vector<vector<int>> &roads, int maxDistance, int &ans){
        if (idx == n){
            if (check(included, roads, maxDistance)) {
                ans++;
            }
            return;
        }
        
        //include
        included.push_back(idx);
        helper(n, idx + 1, included, roads, maxDistance, ans);
        included.pop_back();
        
        //exclude
        helper(n, idx + 1, included, roads, maxDistance, ans);
    }
    
    int numberOfSets(int n, int maxDistance, vector<vector<int>>& roads) {
        int ans = 0;
        vector<int> included;
        
        helper(n, 0, included, roads, maxDistance, ans);
        
        return ans;
    }
};