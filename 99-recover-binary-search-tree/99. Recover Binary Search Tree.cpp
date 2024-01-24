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
    void inorder(TreeNode* root, vector<int> &v){
        if (root == NULL) return;
        inorder(root -> left, v);
        v.push_back(root -> val);
        inorder(root -> right, v);
    }

    void correctTree(TreeNode* root, vector<int> &v, int &idx){
        if (root == NULL) return;
        correctTree(root -> left, v, idx);
        root -> val = v[idx++];
        correctTree(root -> right, v, idx);
    }

    void recoverTree(TreeNode* root) {
        vector<int> v;
        inorder(root, v);
        int first = -1, last = -1;

        for (int i = 1; i < v.size(); i++){
            if (v[i - 1] > v[i]){
                if (first == -1){
                    first = i - 1;
                    last = i;
                }
                else {
                    last = i;
                }
            }
        }

        swap(v[first], v[last]);
        int i = 0;
        correctTree(root, v, i);
    }
};