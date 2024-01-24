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
    void helper(TreeNode* root, int target, vector<int> &curr, vector<vector<int>> &ans){
        if (root == nullptr) return;
        if (root -> left == nullptr && root -> right == nullptr){
            target -= root -> val; 
            curr.push_back(root -> val);

            if (target == 0){
                ans.push_back(curr);
            }

            curr.pop_back();
            return;
        }

        curr.push_back(root -> val);
        target -= root -> val;
        helper(root -> left, target, curr, ans);
        helper(root -> right, target, curr, ans);
        curr.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int target) {
        vector<vector<int>> ans;
        vector<int> curr;

        helper(root, target, curr, ans);

        return ans;
    }
};