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
    void flatten(TreeNode* root) {
        if (root == NULL){
            return;
        }

        if (root -> left == NULL){
            flatten(root -> right);
            return;
        }

        flatten(root -> left);
        flatten(root -> right);

        TreeNode* node; 
        node = root -> left;

        while (node -> right != NULL) node = node -> right;
        node -> right = root -> right;

        root -> right = root -> left;
        root -> left = NULL;
    }
};