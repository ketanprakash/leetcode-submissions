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
    void helper(int s, int e, vector<string> &ans){
        if (s > e) return;
        for (int i = s; i <= e; i++){
            vector<string> left, right;
            string root = to_string(i);
            helper(s, i - 1, left);
            helper(i + 1, e, right);
            if (left.size() == 0) left.push_back("");
            if (right.size() == 0) right.push_back("");

            for (string l : left){
                for (string r : right){
                    ans.push_back(root + '(' + l + ')' + '(' + r + ')');
                }
            }
        }
    }

    TreeNode *deserialize(string data){
        if (data == "") return nullptr;
        string val, left, right;
        for (int i = 0; i < data.size(); i++){
            if (data[i] == '('){
                val = data.substr(0, i);
                data = data.substr(i);
                break;
            }
        }
        int count = 0;
        for (int i = 0; i < data.size(); i++){
            if (data[i] == '(') count++;
            if (data[i] == ')') count--;
            
            if (count == 0){
                left = data.substr(1, i - 1);
                data = data.substr(i + 1);
                break;
            }
        }
        for (int i = 0; i < data.size(); i++){
            if (data[i] == '(') count++;
            if (data[i] == ')') count--;
            
            if (count == 0){
                right = data.substr(1, i - 1);
                data = data.substr(i + 1);
                break;
            }
        }

        TreeNode *root = new TreeNode(stoi(val));
        root -> left = deserialize(left);
        root -> right = deserialize(right);

        return root;
    }

    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> ans; 
        vector<string> strAns;

        helper(1, n, strAns);
        for (int i = 0; i < strAns.size(); i++){
            ans.push_back(deserialize(strAns[i]));
        }

        return ans;
    }
};