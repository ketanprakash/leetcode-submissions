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
    void binaryTreePaths(TreeNode* root, string str, vector<string> &ans){
        if (root -> left == nullptr && root -> right == nullptr){
            if (str.size() != 0) str.insert(str.size(), "->");
            str.insert(str.size(), to_string(root -> val));
            ans.push_back(str);
            return;
        }
        if (root -> left != nullptr){
            string strLeft = str;
            if (strLeft.size() != 0) strLeft.insert(strLeft.size(), "->");
            strLeft.insert(strLeft.size(), to_string(root -> val));
            binaryTreePaths(root -> left, strLeft, ans);
        }

        if (root -> right != nullptr){
            string strRight = str;
            if (strRight.size() != 0) strRight.insert(strRight.size(), "->");
            strRight.insert(strRight.size(), to_string(root -> val));
            binaryTreePaths(root -> right, strRight, ans);
        }
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        if (root == nullptr) return {};
        vector<string> ans; 
        binaryTreePaths(root, "", ans);

        return ans;
    }
};