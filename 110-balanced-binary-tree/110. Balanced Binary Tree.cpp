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
    int helper(TreeNode* root, bool &sol){
        if (root == nullptr) return -1;
        int leftDepth = helper(root -> left, sol);
        int rightDepth = helper(root -> right, sol);
        sol = sol && (abs(leftDepth - rightDepth) <= 1);
        
        return max(leftDepth, rightDepth) + 1;
    }

    bool isBalanced(TreeNode* root) {
        bool sol = true;
        helper(root, sol);

        return sol;
    }
};