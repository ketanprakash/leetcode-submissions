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
    int helper(TreeNode *root, int toAdd){
        if (root == nullptr) return 0;
        int rightVal = helper(root -> right, toAdd);
        int val = root -> val;
        int leftVal = helper(root -> left, val + rightVal + toAdd);

        root -> val += rightVal + toAdd;

        return rightVal + val + leftVal;
    }

    TreeNode* convertBST(TreeNode* root) {
        helper(root, 0);

        return root;
    }
};