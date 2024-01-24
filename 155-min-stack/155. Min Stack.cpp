class MinStack {
public:
    stack<long long> st;
    long long minVal;

    void push(long long val) {
        if (st.empty()){
            minVal = val;
            st.push(minVal);
        }
        else if (val < minVal){
            st.push(val - minVal + val);
            minVal = val;
        }
        else st.push(val);
    }
    
    void pop() {
        if (st.top() < minVal) minVal = 2 * minVal - st.top();
        st.pop();
    }
    
    long long top() {
        if (st.top() < minVal) return minVal;
        return st.top();
    }
    
    long long getMin() {
        return minVal;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * long long param_3 = obj->top();
 * long long param_4 = obj->getMin();
 */