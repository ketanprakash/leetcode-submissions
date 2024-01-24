#define mod 1000000007
class Solution {
public:
    long long countPaths(long long n, vector<vector<int>>& roads) {
        vector<pair<long long, long long>> graph[n];
        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> q;
        vector<pair<long long, long long>> dist(n, {-1, 0});

        dist[0] = {0, 1};

        for (long long i = 0; i < roads.size(); i++){
            graph[roads[i][0]].push_back({roads[i][1], roads[i][2]});
            graph[roads[i][1]].push_back({roads[i][0], roads[i][2]});
        }

        q.push({0, 0});

        while (!q.empty()){
            long long distNode = q.top().first;
            long long node = q.top().second;
            q.pop();

            for (pair<long long, long long> p : graph[node]){
                long long child = p.first;
                long long wt = p.second;
                if (dist[child].first == -1 || dist[child].first > distNode + wt){
                    dist[child] = {distNode + wt, dist[node].second};
                    q.push({dist[child].first, child});
                }
                else if (dist[child].first == distNode + wt){
                    dist[child].second = (dist[child].second % mod + dist[node].second % mod) % mod;
                }
            }
        }

        return dist[n - 1].second;
    }
};