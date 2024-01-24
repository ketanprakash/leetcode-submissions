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
    string helper(TreeNode *root, unordered_map<string, int> &m, vector<TreeNode*> &ans){
        if (root == nullptr) return "";

        string left = helper(root -> left, m, ans);
        string right = helper(root -> right, m, ans);

        string serial = to_string(root -> val) + '(' + left + ')' + '(' + right + ')';

        if (m[serial] == 1){
            ans.push_back(root);
        } 

        m[serial]++;
        return serial;
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string, int> m;
        vector<TreeNode*> ans;
        helper(root, m, ans);
        

        return ans;
    }
};