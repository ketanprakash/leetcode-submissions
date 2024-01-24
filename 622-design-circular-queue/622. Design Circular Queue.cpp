struct Node{
    int val; 
    Node *next; 

    Node(int val){
        this -> val = val; 
        next = nullptr;
    }
};

class MyCircularQueue {
public:
    Node *front = nullptr, *rear = nullptr;
    int size, k;
    MyCircularQueue(int k) {
        size = k;
        this -> k = k;
    }
    
    bool enQueue(int value) {
        if (size == 0) return false;
        if (front == nullptr){
            front = new Node(value);
            rear = front;
        }
        else {
            rear -> next = new Node(value);
            rear = rear -> next;
        }
        size--;
        return true;
    }
    
    bool deQueue() {
        if (size == k) return false;
        if (front == rear) {
            front = nullptr; 
            rear = nullptr;
        }
        else front = front -> next;
        size++;
        return true;
    }
    
    int Front() {
        if (size == k) return -1;
        return front -> val;
    }
    
    int Rear() {
        if (size == k) return -1;
        return rear -> val;
    }
    
    bool isEmpty() {
        return size == k;
    }
    
    bool isFull() {
        return size == 0;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */