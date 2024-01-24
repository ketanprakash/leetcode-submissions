class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses);
        queue<int> q;

        int u, v; 
        for (int i = 0; i < prerequisites.size(); i++){
            u = prerequisites[i][1], v = prerequisites[i][0];
            graph[u].push_back(v);
            indegree[v]++;
        }
        int count = 0; 
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) q.push(i);
        }

        while (!q.empty()){
            int node = q.front(); 
            q.pop(); 
            count++;

            for (int child : graph[node]){
                indegree[child]--;
                if (indegree[child] == 0){
                    q.push(child);
                }
            }
        }

        return count == numCourses;
    }
};