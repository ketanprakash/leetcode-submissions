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
    void helper(TreeNode* root, int &sum, int &count, int &ans){
        if (root == nullptr){
            sum = 0; 
            count = 0; 
            ans = 0;
            return;
        }

        int sumLeft, countLeft, ansLeft, sumRight, countRight, ansRight;

        helper(root -> left, sumLeft, countLeft, ansLeft);
        helper(root -> right, sumRight, countRight, ansRight);

        sum = sumLeft + sumRight + root -> val;
        count = countLeft + countRight + 1; 
        ans = ansLeft + ansRight + (root -> val == sum / count ? 1 : 0);
    }

    int averageOfSubtree(TreeNode* root) {
        int sum, ans, count;

        helper(root, sum, count, ans);

        return ans;
    }
};