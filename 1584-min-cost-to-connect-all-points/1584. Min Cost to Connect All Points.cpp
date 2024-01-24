class Solution {
public:
    int dist(int u, int v, vector<vector<int>> &points){
        return abs(points[u][0] - points[v][0]) + abs(points[u][1] - points[v][1]);
    }

    int findParent(int u, vector<int> &parent){
        if (parent[u] == u) return u;
        return findParent(parent[u], parent);
    }

    void doUnion(int u, int v, vector<int> &parent){
        u = findParent(u, parent);
        v = findParent(v, parent);

        parent[u] = v;
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q; 

        for (int i = 0; i < points.size(); i++){
            for (int j = i + 1; j < points.size(); j++){
                if (i == j) continue;

                q.push({dist(i, j, points), {i, j}});
            }
        }

        vector<int> parent(points.size());

        for (int i = 0; i < parent.size(); i++) parent[i] = i;

        int sum = 0;
        while (!q.empty()){
            int wt = q.top().first;
            int u = q.top().second.first;
            int v = q.top().second.second;
            q.pop();

            if (findParent(u, parent) != findParent(v, parent)){
                sum += wt;

                doUnion(u, v, parent);
            }
        }

        return sum;
    }
};