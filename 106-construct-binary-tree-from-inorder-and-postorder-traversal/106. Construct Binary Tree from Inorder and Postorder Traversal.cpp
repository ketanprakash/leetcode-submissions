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
    TreeNode* helper(vector<int> &inorder, vector<int> &postorder, unordered_map<int, int> &idx, int si, int ei, int sp, int ep){
        if (si > ei || sp > ep) return nullptr;
        int rootIdx = idx[postorder[ep]];
        TreeNode *root = new TreeNode(postorder[ep]);

        root -> left = helper(inorder, postorder, idx, si, rootIdx - 1, sp, sp + rootIdx - 1 - si);
        root -> right = helper(inorder, postorder, idx, rootIdx + 1, ei, sp + rootIdx - si, ep - 1);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> idx; 

        for (int i = 0; i < inorder.size(); i++){
            idx[inorder[i]] = i; 
        }

        return helper(inorder, postorder, idx, 0, inorder.size() - 1, 0, postorder.size() - 1);
    }
};