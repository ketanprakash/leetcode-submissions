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

class BSTIterator {
public:
    stack<TreeNode*> st; 
    bool reverse;

    BSTIterator(TreeNode* root, bool reverse) {
        this -> reverse = reverse;
        pushAll(root);
    }
    
    void pushAll(TreeNode* root){
        if (root == NULL) return;
        if (!reverse){
            while (root != NULL){
                st.push(root);
                root = root -> left;
            }
        }
        else {
            while (root != NULL){
                st.push(root);
                root = root -> right;
            }
        }
    }
    int next() {
        TreeNode* root = st.top();
        st.pop(); 
        int val = root -> val;
        pushAll(reverse ? root -> left : root -> right);

        return val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        BSTIterator b1(root, false);
        BSTIterator b2(root, true);

        int s = b1.next(), e = b2.next();

        while (s < e){
            if (s + e == k) return true;
            if (s + e < k) s = b1.next();
            else e = b2.next();
        }

        return false;
    }
};