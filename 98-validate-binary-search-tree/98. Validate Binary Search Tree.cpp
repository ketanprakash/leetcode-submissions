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
    bool helper(TreeNode *root, long long &mx, long long &mn){
        if (root == nullptr) return true;
        long long mxLeft = INT_MIN - 1LL; 
        long long mnLeft = INT_MAX + 1LL;
        long long mxRight = INT_MIN - 1LL; 
        long long mnRight = INT_MAX + 1LL;
        long long u = root -> val;

        bool left = helper(root -> left, mxLeft, mnLeft);
        bool right = helper(root -> right, mxRight, mnRight);

        mx = max({u, mxLeft, mxRight});
        mn = min({u, mnLeft, mnRight});

        return left && right && u > mxLeft && u < mnRight;
    }

    bool isValidBST(TreeNode* root) {
        long long mx, mn;

        return helper(root, mx, mn);
    }
};