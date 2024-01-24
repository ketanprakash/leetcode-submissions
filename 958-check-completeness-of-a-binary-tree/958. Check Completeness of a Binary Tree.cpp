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
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q; 
        q.push(root);

        TreeNode *node;
        while (!q.empty()){
            node = q.front(); 
            q.pop(); 

            if (node == nullptr){
                while (q.front() == nullptr) q.pop();
                if (!q.empty()) return false;
                continue;
            }
            q.push(node -> left);
            q.push(node -> right);
        }

        return true;
    }
};