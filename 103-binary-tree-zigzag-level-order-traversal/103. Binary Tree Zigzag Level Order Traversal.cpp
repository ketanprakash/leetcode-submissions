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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root == nullptr) return {};
        vector<vector<int>> v;
        deque<TreeNode*> q; 
        bool rev = false;
        TreeNode *node;
        q.push_back(root);

        while (!q.empty()){
            int size = q.size(); 
            v.push_back({});
            if (rev == false){
                for (int i = 0; i < size; i++){
                    node = q.front();
                    q.pop_front();
                    if (node -> left) q.push_back(node -> left);
                    if (node -> right) q.push_back(node -> right);
                    v.back().push_back(node -> val);
                }
            }
            else {
                for (int i = 0; i < size; i++){
                    node = q.back();
                    q.pop_back();
                    if (node -> right) q.push_front(node -> right);
                    if (node -> left) q.push_front(node -> left);
                    v.back().push_back(node -> val);
                }
            }
            rev = !rev;
        }

        return v;
    }
};