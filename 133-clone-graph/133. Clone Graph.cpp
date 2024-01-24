/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* root) {
        if (root == nullptr) return nullptr;
        unordered_map<Node*, Node*> vis;
        Node *newRoot = new Node(root -> val);
        vis[root] = newRoot;
        queue<Node*> q1, q2;  
        q1.push(root);
        q2.push(newRoot);

        Node *node, *newNode;
        while (!q1.empty()){
            node = q1.front();
            q1.pop(); 
            newNode = q2.front();
            q2.pop();

            for (Node *child : node -> neighbors){
                if (vis.count(child)){
                    (newNode -> neighbors).push_back(vis[child]);
                }
                else {
                    Node *newChild = new Node(child -> val);
                    (newNode -> neighbors).push_back(newChild);
                    vis[child] = newChild;
                    q1.push(child);
                    q2.push(newChild);
                }
            }
        }

        return newRoot;
    }
};