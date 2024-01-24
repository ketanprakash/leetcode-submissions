class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<int> dist1(n, -1), dist2(n, -1);
        dist1[node1] = 0; dist2[node2] = 0;

        queue<pair<int, int>> q; 
        int node, child, dist;

        q.push({node1, 0});
        while (!q.empty()){
            node = q.front().first;
            dist = q.front().second;
            q.pop();

            if (edges[node] != -1){
                child = edges[node];
                if (dist1[child] == -1 || dist1[child] > dist + 1){
                    dist1[child] = dist + 1;
                    q.push({child, dist1[child]});
                }
            }
        }

        q.push({node2, 0});
        while (!q.empty()){
            node = q.front().first;
            dist = q.front().second;
            q.pop();

            if (edges[node] != -1){
                child = edges[node];
                if (dist2[child] == -1 || dist2[child] > dist + 1){
                    dist2[child] = dist + 1;
                    q.push({child, dist2[child]});
                }
            }
        }
        
        int ans = -1; dist = -1;
        for (int i = 0; i < n; i++){
            if (dist1[i] != -1 && dist2[i] != -1){
                if (dist == -1 || dist > max(dist1[i], dist2[i])){
                    dist = max(dist1[i], dist2[i]);
                    ans = i;
                }
            }
        }

        return ans;
    }
};