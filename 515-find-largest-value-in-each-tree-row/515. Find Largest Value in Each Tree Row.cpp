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
    vector<int> largestValues(TreeNode* root) {
        if (root == nullptr) return {};
        vector<int> v; 
        queue<TreeNode*> q;

        q.push(root);
        int mx, n;
        TreeNode *node;
        while (!q.empty()){
            mx = INT_MIN;
            n = q.size(); 

            for (int i = 0; i < n; i++){
                node = q.front(); 
                q.pop(); 
                mx = max(mx, node -> val);
                if (node -> left != nullptr) q.push(node -> left);
                if (node -> right != nullptr) q.push(node -> right);
            }
            v.push_back(mx);
        }

        return v;
    }
};