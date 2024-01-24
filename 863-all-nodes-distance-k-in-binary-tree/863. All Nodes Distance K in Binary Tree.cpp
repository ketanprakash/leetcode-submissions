/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    // void findTargetDist(TreeNode* root, TreeNode* target, int &dist){
    //     if (root == target) {
    //         dist = 0;
    //         return;
    //     }
    //     if (root == NULL){
    //         dist = -1;
    //         return;
    //     }

    //     int dist1, dist2;
    //     findTargetDist(root -> left, target, dist1);
    //     findTargetDist(root -> right, target, dist2);

    //     if (dist1 != -1) dist = dist1 + 1;
    //     else if (dist2 != -1) dist = dist2 + 1;
    //     else dist = -1;
    // }

    // void helper(TreeNode* root, TreeNode* target, int k, vector<int> &v){
    //     if (root == NULL) return;
    //     if (k < 0) return;
    //     if (k == 0) {
    //         v.push_back(root -> val);
    //         return;
    //     }
    //     if (root == target){
    //         helper(root -> left, target, k - 1, v);
    //         helper(root -> right, target, k - 1, v);
    //         return;
    //     }

    //     int leftDist, rightDist;
    //     findTargetDist(root -> left, target, leftDist);
    //     findTargetDist(root -> right, target, rightDist);

    //     if (leftDist == -1 && rightDist == -1){
    //         helper(root -> left, target, k - 1, v);
    //         helper(root -> right, target, k - 1, v);
    //     }
    //     else if (leftDist != -1){
    //         helper(root -> left, target, k, v);
    //         if (k - leftDist - 1 > 0){
    //             helper(root -> right, target, k - leftDist - 2, v);
    //         }
    //         else if (k - leftDist - 1 == 0) v.push_back(root -> val);
    //     }
    //     else if (rightDist != -1){
    //         if (k - rightDist - 1 > 0){
    //             helper(root -> left, target, k - rightDist - 2, v);
    //         }
    //         else if (k - rightDist - 1 == 0) v.push_back(root -> val);
    //         helper(root -> right, target, k, v);
    //     }
    // }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        // if (k == 0){
        //     return {target -> val};
        // }
        // vector<int> v;
        // helper(root, target, k, v);
        // return v;
        vector<int> v;
        unordered_map<TreeNode*, TreeNode*> parent;
        unordered_set<TreeNode*> vis;
        parent[root] = NULL;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});

        TreeNode* node;
        while (!q.empty()){
            node = q.front().first;
            q.pop();

            if (node -> left != NULL){
                q.push({node -> left, 0});
                parent[node -> left] = node;
            }
            if (node -> right != NULL){
                q.push({node -> right, 0});
                parent[node -> right] = node;
            }
        }

        q.push({target, 0});
        vis.insert(target);

        int dist;
        while (!q.empty()){
            node = q.front().first;
            dist = q.front().second;
            q.pop();

            if (dist == k){
                v.push_back(node -> val);
                continue;
            }

            if (parent[node] != NULL && vis.find(parent[node]) == vis.end()){
                q.push({parent[node], dist + 1});
                vis.insert(parent[node]);
            }

            if (node -> left != NULL && vis.find(node -> left) == vis.end()){
                q.push({node -> left, dist + 1});
                vis.insert(node -> left);
            }

            if (node -> right != NULL && vis.find(node -> right) == vis.end()){
                q.push({node -> right, dist + 1});
                vis.insert(node -> right);
            }
        }

        return v;
    }
};