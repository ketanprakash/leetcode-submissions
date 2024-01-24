class Solution {
public:
    long long helper(string &source, string &target, int prev, int idx, unordered_map<string, unordered_map<string, long long>> &dist){
        if (prev == source.size() && idx == source.size()) return 0;
        if (idx == source.size()) return 1e9;

        long long ans = 1e9;
        string u = source.substr(prev, idx - prev + 1);
        string v = target.substr(prev, idx - prev + 1);

        if (u == v){
            ans = min(ans, helper(source, target, idx + 1, idx + 1, dist));
        }

        if (dist.count(u) && dist[u].count(v)){
            ans = min(ans, dist[u][v] + helper(source, target, idx + 1, idx + 1, dist));
        }

        ans = min(ans, helper(source, target, prev, idx + 1, dist));

        return ans;
    }

    long long minimumCost(string source, string target, vector<string>& original, vector<string>& changed, vector<int>& cost) {
        int n = original.size();
        unordered_map<string, unordered_map<string, long long>> dist;

        string o, c, mid;
        for (int i = 0; i < n; i++){
            o = original[i], c = changed[i];

            dist[o][c] = cost[i];
            dist[o][o] = 0;
            dist[c][c] = 0;
        }

        for (int k = 0; k < n; k++){
            mid = changed[k];
            if (!dist.count(mid)) continue;
            for (int i = 0; i < n; i++){
                o = original[i];
                if (!dist.count(o) || !dist[o].count(mid)) continue;
                for (int j = 0; j < n; j++){
                    c = changed[j];
                    if (!dist[mid].count(c)) continue;

                    if (!dist[o].count(c)){
                        dist[o][c] = dist[o][mid] + dist[mid][c];
                    }
                    else {
                        dist[o][c] = min(dist[o][c], dist[o][mid] + dist[mid][c]);
                    }
                }
            }
        }
        long long ans = helper(source, target, 0, 0, dist);

        return ans >= 1e9 ? -1 : ans;
    }
};