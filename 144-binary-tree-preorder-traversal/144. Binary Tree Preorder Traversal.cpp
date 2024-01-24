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
    vector<int> preorderTraversal(TreeNode* root) {
        if (root == nullptr) return {}; 

        stack<TreeNode*> st; 
        vector<int> v;
        TreeNode *node;
        st.push(root);

        while (!st.empty()){
            node = st.top(); 
            st.pop(); 
            v.push_back(node -> val);

            if (node -> right) st.push(node -> right);
            if (node -> left) st.push(node -> left);
        }

        return v;
    }
};