struct Node{
    pair<int, pair<int, int>> data; 
    Node* next; 
    Node* prev;

    Node(pair<int, pair<int, int>> data){
        this -> data = data;
        this -> next = NULL;
        this -> prev = NULL;
    }
};

class List{
    public:
    Node* front; 
    Node* rear;

    List(){
        front = new Node({-1, {-1, -1}});
        rear = new Node({-1, {-1, -1}});
        front -> next = rear;
        rear -> prev = front;
    }
};

void printList(List *l){
    Node* front = l -> front;
    while (front != NULL){
        cout << '{' << (front -> data).second.first << "," << (front -> data).second.second << '}';
        front = front -> next;
    }
    cout << endl;
}

void printCache(map<int, List*> m){
    for (auto i : m){
        printList(i.second);
    }
    cout << endl;
}

class LFUCache {
public:
    int capacity; 
    int size; 
    map<int, List*> freqToList;
    unordered_map<int, Node*> keyToNode;

    LFUCache(int capacity) {
        this -> capacity = capacity;
        this -> size = 0;
    }
    
    void addNode(int freq, int key, int value){
        if (freqToList.find(freq) == freqToList.end()){
            freqToList[freq] = new List();
        }
        Node* front = (freqToList[freq]) -> front;
        Node* rear = (freqToList[freq]) -> rear;
        Node* newNode = new Node({freq, {key, value}});
        keyToNode[key] = newNode;
        newNode -> prev = rear -> prev;
        newNode -> next = rear;

        rear -> prev -> next = newNode;
        rear -> prev = newNode;
        size++;
    }

    void deleteNode(int freq, int key){
        Node* front = freqToList[freq] -> front;
        Node* rear = freqToList[freq] -> rear;

        Node* toDelete = keyToNode[key];
        
        toDelete -> prev -> next = toDelete -> next;
        toDelete -> next -> prev = toDelete -> prev;

        delete toDelete;
        size--;

        keyToNode.erase(key);
        if (front -> next == rear){
            freqToList.erase(freq);
        }
    }

    void deleteNode(){
        if (size == 0) return;
        int freq = (freqToList.begin()) -> first;
        Node* front = (freqToList.begin()) -> second -> front;
        Node* rear = (freqToList.begin()) -> second -> rear;

        Node* toDelete = front -> next;
        int key = (toDelete -> data).second.first;
        toDelete -> prev -> next = toDelete -> next;
        toDelete -> next -> prev = toDelete -> prev;

        delete toDelete;
        size--;
        keyToNode.erase(key);
        if (front -> next == rear){
            freqToList.erase(freq);
        }
    }

    int get(int key) {
        if (keyToNode.find(key) == keyToNode.end()){
            return -1;
        }

        int freq = (keyToNode[key] -> data).first;
        int value = (keyToNode[key] -> data).second.second;
        deleteNode(freq, key);
        addNode(freq + 1, key, value);

        // printCache(freqToList);
        return value;
    }
    
    void put(int key, int value) {
        if (keyToNode.find(key) == keyToNode.end()){
            if (capacity == size) deleteNode();
            addNode(0, key, value);
        }
        else {
            int freq = (keyToNode[key] -> data).first;
            deleteNode(freq, key);
            addNode(freq + 1, key, value);
        }
        // printCache(freqToList);
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */