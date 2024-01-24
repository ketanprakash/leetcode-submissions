class FreqStack {
public:
    priority_queue<pair<pair<int, int>, int>> q;
    unordered_map<int, int> freq;
    int idx;

    FreqStack() {
        idx = 0;    
    }
    
    void push(int val) {
        freq[val]++;
        q.push({{freq[val], idx++}, val});
    }
    
    int pop() {
        int val = q.top().second;
        freq[val]--;
        q.pop();
        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */