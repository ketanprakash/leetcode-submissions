class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int count = 0; 
        queue<int> q; 
        vector<int> vis(n);

        for (int i = 0; i < n; i++){
            if (!vis[i]){
                count++;
                vis[i] = 1;
                q.push(i);

                while (!q.empty()){
                    int node = q.front();
                    q.pop();

                    for (int adj = 0; adj < n; adj++){
                        if (isConnected[node][adj] && !vis[adj]){
                            vis[adj] = 1;
                            q.push(adj);
                        }
                    }
                }
            }
        }

        return count;
    }
};