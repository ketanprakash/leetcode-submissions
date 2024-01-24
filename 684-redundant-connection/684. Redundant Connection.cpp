class Solution {
public:
    void doUnion(int u, int v, vector<int> &parent){
        u = findParent(u, parent);
        v = findParent(v, parent);
        parent[v] = u;
    }

    int findParent(int u, vector<int> &parent){
        if (parent[u] == u) return u;
        return parent[u] = findParent(parent[u], parent);
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = 0; 
        for (int i = 0; i < edges.size(); i++){
            n = max({n, edges[i][0], edges[i][1]});
        }

        vector<int> parent(n + 1);
        for (int i = 1; i < n + 1; i++) parent[i] = i;

        vector<int> ans; 
        int u, v;
        for (int i = 0; i < edges.size(); i++){
            u = edges[i][0];
            v = edges[i][1];

            if (findParent(u, parent) == findParent(v, parent)){
                ans = {u, v};
            }
            else doUnion(u, v, parent);
        }

        return ans;
    }
};