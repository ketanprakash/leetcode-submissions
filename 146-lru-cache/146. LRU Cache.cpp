struct Node{
    pair<int, int> val; 
    Node *next; 
    Node *prev; 

    Node(pair<int, int> val){
        this -> val = val; 
        this -> next = nullptr; 
        this -> prev = nullptr;
    }
};

class LRUCache {
public:
    unordered_map<int, Node*> m; 
    Node *head, *tail; 
    int size; 
    int capacity;

    LRUCache(int capacity) {
        this -> head = new Node({-1, -1});
        this -> tail = new Node({-1, -1});
        head -> next = tail; 
        tail -> prev = head;
        this -> size = 0; 
        this -> capacity = capacity;
    }

    void insert(int key, int value){
        Node* newNode = new Node({key, value});
        m[key] = newNode;
        newNode -> prev = tail -> prev;
        newNode -> prev -> next = newNode; 
        newNode -> next = tail;
        tail -> prev = newNode;
    }

    void remove(int key){
        Node* toRemove = m[key];
        Node* prevToRemove = toRemove -> prev; 

        prevToRemove -> next = prevToRemove -> next -> next; 
        prevToRemove -> next -> prev = prevToRemove;
        m.erase(key);
    }

    void remove(){
        m.erase((head -> next -> val).first);
        head -> next = head -> next -> next; 
        head -> next -> prev = head;
    }
    
    int get(int key) {
        if (!m.count(key)) return -1; 
        int val = (m[key] -> val).second;
        remove(key);
        insert(key, val);

        return val;
    }
    
    void put(int key, int value) {
        if (m.count(key)) {
            remove(key);
            insert(key, value);
            return;
        }

        if (size == capacity){
            remove(); 
            size--;
        }
        insert(key, value);
        size++;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */