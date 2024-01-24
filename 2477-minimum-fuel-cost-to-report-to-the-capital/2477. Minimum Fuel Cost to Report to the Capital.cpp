class Solution {
public:
    void helper(int node, vector<vector<int>> &graph, int seats, vector<int> &vis, long long &num, long long &ans){
        ans = 0, num = 1;

        long long ansChild, numChild;
        for (int child : graph[node]){
            if (vis[child]) continue;
            vis[child] = 1;
            helper(child, graph, seats, vis, numChild, ansChild);
            ans += ansChild + ceil((double)numChild / seats);
            num += numChild;
        }
    }

    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n = roads.size() + 1;
        vector<int> vis(n);
        long long num, ans;

        vector<vector<int>> graph(n);

        for (int i = 0; i < roads.size(); i++){
            graph[roads[i][0]].push_back(roads[i][1]);
            graph[roads[i][1]].push_back(roads[i][0]);
        }
        vis[0] = 1;
        helper(0, graph, seats, vis, num, ans);

        return ans;
    }
};