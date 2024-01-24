class StockSpanner {
public:
    stack<pair<int, int>> st; 
    int idx;

    StockSpanner() {
        idx = -1;
    }
    
    int next(int price) {
        idx++;
        while (!st.empty() && price >= st.top().first){
            st.pop();
        }
        int val = st.empty() ? idx + 1 : idx - st.top().second;
        st.push({price, idx});

        return val;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */