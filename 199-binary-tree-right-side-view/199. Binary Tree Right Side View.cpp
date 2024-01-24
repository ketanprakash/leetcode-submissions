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
    vector<int> rightSideView(TreeNode* root) {
        if (root == nullptr) return {};
        queue<TreeNode*> q;
        q.push(root);
        vector<int> v; 
        TreeNode* node;

        while (!q.empty()){
            int size = q.size(); 
            v.push_back((q.front()) -> val);
            for (int i = 0; i < size; i++){
                node = q.front(); 
                q.pop();

                if (node -> right) q.push(node -> right);
                if (node -> left) q.push(node -> left);
            }
        }

        return v;
    }
};