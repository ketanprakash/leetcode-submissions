struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const
    {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
 
        if (hash1 != hash2) {
            return hash1 ^ hash2;              
        }
         
        // If hash1 == hash2, their XOR is zero.
        return hash1;
    }
};

class DetectSquares {
public:
    unordered_map<int, vector<vector<int>>> x; 
    unordered_map<int, vector<vector<int>>> y; 
    unordered_map<pair<int, int>, int, hash_pair> points;
    DetectSquares() {
        
    }
    
    void add(vector<int> point) {
        x[point[0]].push_back(point);
        y[point[1]].push_back(point);
        points[{point[0], point[1]}]++;
    }
    
    int count(vector<int> point) {
        int count = 0;
        for (vector<int> &xPoint : x[point[0]]){
            for (vector<int> &yPoint : y[point[1]]){
                count += points.count({yPoint[0], xPoint[1]}) ? points[{yPoint[0], xPoint[1]}] : 0;
            }
        }

        return count;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */