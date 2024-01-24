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
    int findBottomLeftValue(TreeNode* root) {
        if (root == nullptr) return 0;

        queue<TreeNode*> q; 
        q.push(root);

        TreeNode *node = root;
        int val;

        while (!q.empty()){
            int size = q.size(); 
            val = (q.front()) -> val;

            for (int i = 0; i < size; i++){
                node = q.front();
                q.pop();

                if (node -> left) q.push(node -> left);
                if (node -> right) q.push(node -> right);
            }
        }

        return val;
    }
};