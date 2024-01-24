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
    vector<int> inorderTraversal(TreeNode* root) {
        if (root == nullptr) return {}; 

        stack<TreeNode*> st;
        vector<int> v; 
        TreeNode *node = root;

        while (!st.empty() || node != nullptr){
            if (node == nullptr){
                node = st.top(); 
                st.pop(); 
                v.push_back(node -> val);
                node = node -> right;
            }
            else {
                st.push(node);
                node = node -> left;
            }
        }

        return v;
    }
};