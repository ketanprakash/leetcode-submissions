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
    int minDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        if (root -> left == nullptr && root -> right == nullptr) return 1;
        int ans = INT_MAX;

        if (root -> left != nullptr){
            ans = min(minDepth(root -> left) + 1, ans);
        }

        if (root -> right != nullptr){
            ans = min(minDepth(root -> right) + 1, ans);
        }

        return ans;
    }
};