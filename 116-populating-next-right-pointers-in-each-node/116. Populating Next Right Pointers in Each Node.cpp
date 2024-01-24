/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr) return nullptr;
        queue<Node*> q; 

        q.push(root);
        q.push(nullptr);
        
        Node* node;
        while (!q.empty()){
            node = q.front();
            q.pop();

            if (node == nullptr){
                if (!q.empty()) q.push(nullptr);
            }
            else {
                node -> next = q.front();
                if (node -> left != nullptr) q.push(node -> left);
                if (node -> right != nullptr) q.push(node -> right);
            }
        }

        return root;
    }
};