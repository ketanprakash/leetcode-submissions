class DataStream {
public:
    deque<pair<int, int>> q;

    int value, k, size = 0;

    DataStream(int value, int k) {
        this -> value = value;
        this -> k = k;
    }
    
    bool consec(int num) {
        if (q.size() == 0 || q.back().first != num){
            q.push_back({num, 1});
        }
        else {
            int freq = q.back().second;
            q.pop_back();
            q.push_back({num, freq + 1});
        }
        size++;

        if (size > k){
            int n1 = q.front().first;
            int freq1 = q.front().second;
            q.pop_front();

            freq1--;
            if (freq1 != 0) q.push_front({n1, freq1});
            size--;
        }
        
        if (size == k && q.size() == 1 && q.front().first == value) return true;
        return false;
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */