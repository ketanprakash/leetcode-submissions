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
    TreeNode* helper(vector<int> &preorder, int sp, int ep){
        if (sp > ep) return NULL;

        int rootData = preorder[sp];
        TreeNode* root = new TreeNode(rootData);

        int rightIdx = upper_bound(preorder.begin() + sp + 1, preorder.begin() + ep + 1, rootData) - preorder.begin();

        root -> left = helper(preorder, sp + 1, rightIdx - 1);
        root -> right = helper(preorder, rightIdx, ep);

        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return helper(preorder, 0, preorder.size() - 1);
    }
};