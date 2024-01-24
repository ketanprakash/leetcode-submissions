/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return head;
        Node *temp = head, *node, *temp1; 

        while (temp != nullptr){
            node = new Node(temp -> val);
            node -> next = temp -> next;
            temp -> next = node;

            temp = temp -> next -> next;
        }

        temp = head; 

        while (temp != nullptr && temp -> next != nullptr){
            if (temp -> random != nullptr) temp -> next -> random = temp -> random -> next; 
            temp = temp -> next -> next;
        }
        node = head -> next;
        temp = head;
        temp1;

        while (temp != nullptr && temp -> next != nullptr){
            temp1 = temp -> next; 
            temp -> next = temp -> next -> next;
            temp = temp -> next;

            if (temp1 -> next != nullptr) temp1 -> next = temp1 -> next -> next;
        }

        return node;
    }
};