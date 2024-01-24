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
    int helper(TreeNode *root, int &ans){
        if (root == nullptr) return -1e6;

        int left = helper(root -> left, ans);
        int right = helper(root -> right, ans);

        ans = max(ans, root -> val + max(left, 0) + max(right, 0));

        return root -> val + max({left, right, 0});
    }

    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN; 
        helper(root, ans);

        return ans;
    }
};