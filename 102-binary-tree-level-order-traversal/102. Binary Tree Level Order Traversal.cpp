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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr) return {};
        vector<vector<int>> v; 
        queue<TreeNode*> q; 

        q.push(root);
        TreeNode* node;
        while (!q.empty()){
            int size = q.size(); 
            v.push_back({});

            for (int i = 0; i < size; i++){
                node = q.front(); 
                q.pop(); 
                v.back().push_back(node -> val);
                if (node -> left != nullptr) q.push(node -> left);
                if (node -> right != nullptr) q.push(node -> right);
            }
        }

        return v;
    }
};