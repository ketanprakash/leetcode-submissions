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
    void helper(TreeNode *root, int freq[], int &ans){
        if (root == nullptr) return;
        freq[root -> val]++;
        if (root -> left == nullptr && root -> right == nullptr){
            int odd = 0; 
            int sum = 0;
            for (int i = 0; i < 10; i++){
                if (freq[i] % 2 != 0) odd++;
                sum += freq[i];
            }
            if (sum % 2 == 0 && odd == 0) ans++;
            else if (sum % 2 != 0 && odd == 1) ans++;
        }
        helper(root -> left, freq, ans);
        helper(root -> right, freq, ans);
        freq[root -> val]--;
    }

    int pseudoPalindromicPaths (TreeNode* root) {
        int ans = 0; 
        int freq[10] = {0};
        helper(root, freq, ans);

        return ans;
    }
};