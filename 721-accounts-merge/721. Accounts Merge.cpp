class Solution {
public:
    vector<int> parent;

    int findParent(int u){
        if (parent[u] == u) return u;
        return parent[u] = findParent(parent[u]);
    }

    void doUnion(int u, int v){
        u = findParent(u);
        v = findParent(v);

        parent[u] = v;
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        parent.resize(n);

        for (int i = 0; i < parent.size(); i++){
            parent[i] = i;
        }

        unordered_map<string, int> m;
        for (int i = 0; i < n; i++){
            for (int j = 1; j < accounts[i].size(); j++) {
                if (!m.count(accounts[i][j])) m[accounts[i][j]] = i;
                else doUnion(i, m[accounts[i][j]]);
            }
        }

        for (int i = 0; i < accounts.size(); i++){
            accounts[i] = {accounts[i][0]};
        }
        for (auto p : m){
            accounts[findParent(p.second)].push_back(p.first);
        }

        vector<vector<string>> ans;

        for (int i = 0; i < accounts.size(); i++){
            if (findParent(i) == i) {
                sort(accounts[i].begin() + 1, accounts[i].end());
                ans.push_back(accounts[i]);
            }
        }

        return ans;
    }
};