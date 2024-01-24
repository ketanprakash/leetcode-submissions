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
    int helper(TreeNode* root, int &sol){
        if (root == nullptr) return -1; 

        int leftDepth = helper(root -> left, sol);
        int rightDepth = helper(root -> right, sol);

        sol = max(sol, leftDepth + rightDepth + 2);

        return max(leftDepth, rightDepth) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int sol = 0; 
        helper(root, sol);

        return sol;
    }
};