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
    int findMin(TreeNode *root){
        if (root -> left == nullptr) return root -> val;
        return findMin(root -> left);
    }

    int findMax(TreeNode *root){
        if (root -> right == nullptr) return root -> val;
        return findMax(root -> right);
    }

    bool isValidBST(TreeNode *root, int &sum, int &maxSum){
        if (root == nullptr) return true;
        int sumLeft = 0, sumRight = 0;
        bool leftValid = isValidBST(root -> left, sumLeft, maxSum);
        bool rightValid = isValidBST(root -> right, sumRight, maxSum);
        sum = sumLeft + sumRight + root -> val;

        if (leftValid && rightValid){
            if (root -> left){
                int leftMax = findMax(root -> left);

                if (root -> val <= leftMax) return false;
            }

            if (root -> right){
                int rightMin = findMin(root -> right);

                if (root -> val >= rightMin) return false;
            }

            maxSum = max(maxSum, sum);
            return true;
        }

        return false;
    }

    int maxSumBST(TreeNode* root) {
        int sum = 0, maxSum = 0;
        isValidBST(root, sum, maxSum);

        return maxSum;
    }
};