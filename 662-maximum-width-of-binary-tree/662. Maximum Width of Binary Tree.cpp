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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, int>> q; 
        int size;
        q.push({root, 0});
        long long start, val;
        TreeNode *node; 
        int ans = 0; 

        while (!q.empty()){
            size = q.size(); 
            start = q.front().second;
            for (int i = 0; i < size; i++){
                node = q.front().first; 
                val = q.front().second; 
                q.pop(); 

                if (node -> left) q.push({node -> left, 2 * (val - start)});
                if (node -> right) q.push({node -> right, 2 * (val - start) + 1});
            }
            ans = max((long long)ans, val - start + 1);
        }

        return ans;
    }
};