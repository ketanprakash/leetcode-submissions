/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == nullptr) return "";
        string left = serialize(root -> left);
        string right = serialize(root -> right);

        return to_string(root -> val) + '(' + left + ')' + '(' + right + ')';
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
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
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));