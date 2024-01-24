struct Node{
    string val; 
    Node *next; 
    Node *prev;

    Node(string val){
        this -> val = val; 
        next = nullptr; 
        prev = nullptr;
    }
};

class BrowserHistory {
public:
    Node *head; 
    Node *tail; 
    Node *curr;

    BrowserHistory(string homepage) {
        head = new Node("");
        tail = new Node("");
        curr = new Node(homepage);
        curr -> prev = head; 
        curr -> next = tail; 
        head -> next = curr; 
        tail -> prev = curr;
    }
    
    void visit(string url) {
        Node *newNode = new Node(url);
        newNode -> prev = curr; 
        newNode -> next = tail;
        curr -> next = newNode; 
        tail -> prev = newNode;
        curr = newNode;
    }
    
    string back(int steps) {
        while (curr -> prev != head && steps--){
            curr = curr -> prev;
        }

        return curr -> val;
    }
    
    string forward(int steps) {
        while (curr -> next != tail && steps--){
            curr = curr -> next;
        }
        return curr -> val;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */