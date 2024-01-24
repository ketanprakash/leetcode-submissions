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
    void helper(TreeNode *root, bool left, int &ans){
        if (root == nullptr) return;
        if (left && root -> left == nullptr && root -> right == nullptr){
            ans += root -> val;
            return;
        }

        helper(root -> left, true, ans);
        helper(root -> right, false, ans);
    }

    int sumOfLeftLeaves(TreeNode* root) {
        int ans = 0;

        helper(root, false, ans);

        return ans;
    }
};