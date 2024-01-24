/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void dfs(TreeNode *root, int parent, unordered_map<int, vector<int>> &graph){
        if (root == nullptr) return;
        int u = root -> val;
        if (parent != 0) graph[u].push_back(parent);
        
        if (root -> left != nullptr){
            graph[u].push_back(root -> left -> val);
            dfs(root -> left, u, graph);
        }
        
        if (root -> right != nullptr){
            graph[u].push_back(root -> right -> val);
            dfs(root -> right, u, graph);

        }
    }
    
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int,vector<int>> graph;
        dfs(root, 0, graph);
        queue<pair<int, int>> q;
        
        unordered_map<int, int> dist;
        dist[start] = 0;
        q.push({start, 0});
        int maxDist = 0;
        
        while (!q.empty()){
            int node = q.front().first;
            int dst = q.front().second;
            
            q.pop();
            
            for (int child : graph[node]){
                if (!dist.count(child) || dist[child] > dst + 1){
                    dist[child] = dst + 1;
                    q.push({child, dst + 1});
                }
            }
        }
        
        for (auto p : dist){
            maxDist = max(p.second, maxDist);
        }
        
        return maxDist;
    }
};