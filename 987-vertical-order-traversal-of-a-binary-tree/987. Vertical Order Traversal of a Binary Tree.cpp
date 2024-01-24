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

#include <queue>

struct compare{
    bool operator()(pair<int, pair<int, int>> &p1, pair<int, pair<int, int>> &p2){
        if (p1.first > p2.first) return true;
        else if (p1.first == p2.first && p1.second.first > p2.second.first) return true;
        else if (p1.first == p2.first && p1.second.first == p2.second.first && p1.second.second > p2.second.second) return true;

        return false;
    }
};

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if (root == NULL) return {};
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, compare> pq;
        queue<pair<TreeNode*, pair<int, int>>> q; 

        q.push({root, {0, 0}});
        TreeNode* node;
        int row, col;
        while (!q.empty()){
            node = q.front().first;
            row = q.front().second.first;
            col = q.front().second.second;
            q.pop();

            pq.push({col, {row, node -> val}});

            if (node -> left != NULL) q.push({node -> left, {row + 1, col - 1}});
            if (node -> right != NULL) q.push({node -> right, {row + 1, col + 1}});
        }

        vector<vector<int>> v{{}};
        while (!pq.empty()){
            row = pq.top().second.first;
            col = pq.top().first;
            v.back().push_back(pq.top().second.second);
            pq.pop();

            if (!pq.empty() && pq.top().first != col){
                v.push_back({});
            }
        }

        return v;
    }
};