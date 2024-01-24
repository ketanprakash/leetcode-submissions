class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> graph(n);
        queue<pair<int, int>> q;

        for (int i = 0; i < manager.size(); i++){
            if (manager[i] == -1) continue;
            graph[manager[i]].push_back(i);
        }
        int time, maxTime = 0, node, size; 

        q.push({headID, 0});

        while (!q.empty()){
            size = q.size();
            
            for (int i = 0; i < size; i++){
                node = q.front().first; 
                time = q.front().second; 
                q.pop();
                maxTime = max(maxTime, time);

                for (int child : graph[node]){
                    q.push({child, time + informTime[node]});
                }
            }
        }

        return maxTime;
    }
};