class Solution {
public:
    void helper(int node, vector<vector<int>> &tree, vector<int> &cost, vector<int> &vis, vector<int> &mx, vector<int> &mn, int &count, vector<long long> &coins){
        if (vis[node]) return;
        vis[node] = 1;
        count = 1;
        mx.push_back(cost[node]);
        mn.push_back(cost[node]);
        vector<int> cmx, cmn;
        int ccount;
        for (int child : tree[node]){
            ccount = 0;
            cmx = vector<int>(), cmn = vector<int>();
            helper(child, tree, cost, vis, cmx, cmn, ccount, coins);
            count += ccount;
            
            mx.insert(mx.end(), cmx.begin(), cmx.end());
            mn.insert(mn.end(), cmn.begin(), cmn.end());
            sort(mx.begin(), mx.end(), greater<int>());
            sort(mn.begin(), mn.end());
            if (mx.size() > 3) mx = {mx[0], mx[1], mx[2]};
            if (mn.size() > 2) mn = {mn[0], mn[1]};
        }
        
        if (count < 3) coins[node] = 1;
        else {
            coins[node] = max({(long long)mx[0] * mx[1] * mx[2], (long long)mx[0] * mn[0] * mn[1], (long long)0});
        }
    }
    
    vector<long long> placedCoins(vector<vector<int>>& edges, vector<int>& cost) {
        int n = cost.size();
        vector<vector<int>> tree(n);
        vector<long long> coins(n);
        int u, v;
        unordered_set<int> s;
        for (int i = 0; i < edges.size(); i++){
            u = edges[i][0], v = edges[i][1];
            tree[u].push_back(v);
            tree[v].push_back(u);
        }
        vector<int> traversal;
        vector<int> vis(n);
        int count = 0;
        vector<int> mx, mn;
        helper(0, tree, cost, vis, mx, mn, count, coins);
        return coins;
    }
};