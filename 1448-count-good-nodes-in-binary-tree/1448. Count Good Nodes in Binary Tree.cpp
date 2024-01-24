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
    void helper(TreeNode *root, int maximum, int &count){
        if (root == nullptr) return;

        if (root -> val >= maximum){
            count++;
            maximum = root -> val;
        }

        helper(root -> left, maximum, count);
        helper(root -> right, maximum, count);
    }

    int goodNodes(TreeNode* root) {
        if (root == nullptr) return 0;
        int count = 0; 
        helper(root, root -> val, count);

        return count;
    }
};