struct Node {
    int val; 
    Node *prev; 
    Node *next;

    Node(int val){
        this -> val = val; 
        this -> prev = nullptr; 
        this -> next = nullptr;
    }
};

class MyLinkedList {
public:
    Node *head, *tail;

    MyLinkedList() {
        head = new Node(-1);
        tail = new Node(-1);
        head -> next = tail; 
        tail -> prev = head;
    }
    
    int get(int index) {
        Node *temp = head; 
        while (index--){
            temp = temp -> next;
            if (temp -> next == tail) return -1;
        }

        return temp -> next -> val;
    }
    
    void addAtHead(int val) {
        Node *newNode = new Node(val);
        newNode -> prev = head;
        newNode -> next = head -> next; 
        newNode -> next -> prev = newNode; 
        head -> next = newNode;
    }
    
    void addAtTail(int val) {
        Node *newNode = new Node(val);
        newNode -> next = tail;
        newNode -> prev = tail -> prev; 
        newNode -> prev -> next = newNode; 
        tail -> prev = newNode;
    }
    
    void addAtIndex(int index, int val) {
        Node *temp = head; 
        while (index--){
            temp = temp -> next;
            if (temp == tail) return;
        }
        Node *newNode = new Node(val);
        newNode -> next = temp -> next; 
        newNode -> prev = temp; 
        newNode -> next -> prev = newNode;
        temp -> next = newNode;
    }
    
    void deleteAtIndex(int index) {
        Node *temp = head; 
        while (index--){
            temp = temp -> next;
            if (temp -> next == tail) return;
        }

        temp -> next = temp -> next -> next; 
        temp -> next -> prev = temp;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */