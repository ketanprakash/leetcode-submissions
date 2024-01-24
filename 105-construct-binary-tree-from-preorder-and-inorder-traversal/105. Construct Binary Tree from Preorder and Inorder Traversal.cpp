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
    TreeNode* helper(vector<int> &preorder, vector<int> &inorder, unordered_map<int, int> &m, int sp, int ep, int si, int ei){
        if (sp > ep || si > ei) return nullptr;

        TreeNode *root = new TreeNode(preorder[sp]);
        int rootIdx = m[preorder[sp]];

        root -> left = helper(preorder, inorder, m, sp + 1, sp + rootIdx - si, si, rootIdx - 1);
        root -> right = helper(preorder, inorder, m, sp + rootIdx - si + 1, ep, rootIdx + 1, ei);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> m; 
        for (int i = 0; i < inorder.size(); i++){
            m[inorder[i]] = i;
        }
        return helper(preorder, inorder, m, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }
};