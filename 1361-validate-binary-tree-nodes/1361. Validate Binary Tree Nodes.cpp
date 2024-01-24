class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int> vis(n);
        vector<int> indegree(n);

        for (int i = 0; i < n; i++){
            if (leftChild[i] != -1) indegree[leftChild[i]]++;
            if (rightChild[i] != -1) indegree[rightChild[i]]++;
        }

        queue<int> q; 
        for (int i = 0; i < n; i++){
            if (indegree[i] == 0) q.push(i);
        }
        if (q.size() > 1) return false;

        int node;
        while (!q.empty()){
            node = q.front(); 
            q.pop();

            if (vis[node]) return false;
            vis[node] = 1;

            if (leftChild[node] != -1) q.push(leftChild[node]);
            if (rightChild[node] != -1) q.push(rightChild[node]);
        }

        for (int i = 0; i < n; i++){
            if (!vis[i]) return false;
        }

        return true;
    }
};