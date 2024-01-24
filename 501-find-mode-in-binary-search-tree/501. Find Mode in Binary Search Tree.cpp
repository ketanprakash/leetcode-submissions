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
    void findInorder(TreeNode *root, vector<int> &inorder){
        if (root == nullptr) return;
        findInorder(root -> left, inorder);
        inorder.push_back(root -> val);
        findInorder(root -> right, inorder);
    }

    vector<int> findMode(TreeNode* root) {
        vector<int> inorder;
        findInorder(root, inorder);

        vector<int> ans;
        int maxCount = 0, currCount = 0;
        for (int i = 0; i < inorder.size(); i++){
            currCount++; 
            if (i + 1 == inorder.size() || inorder[i + 1] != inorder[i]){
                if (currCount == maxCount) {
                    ans.push_back(inorder[i]);
                }
                else if (currCount > maxCount){
                    ans = {inorder[i]};
                    maxCount = currCount;
                }
                currCount = 0;
            }
        }

        return ans;
    }
};