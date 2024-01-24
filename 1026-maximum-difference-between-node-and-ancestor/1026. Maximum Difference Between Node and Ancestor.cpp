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
    void helper(TreeNode *root, int &mx, int &mn, int &ans){
        int u = root -> val;
        int mxChild = u;
        int mnChild = u;
        
        if (root -> left != nullptr){
            helper(root -> left, mxChild, mnChild, ans);
 
        }
        
        if (root -> right){
            helper(root -> right, mxChild, mnChild, ans);
        }
        
        ans = max({ans, mxChild - u, u - mnChild});
        
        mn = min({mn, u, mnChild});
        mx = max({mx, u, mxChild});
    }
    
    int maxAncestorDiff(TreeNode* root) {
        int mn = INT_MAX;
        int mx = INT_MIN;
        int ans = 0;
        
        helper(root, mx, mn, ans);
        
        return ans;
    }
};