class Solution {
public:
    int num, n, m;
    vector<int> v;

    Solution(int n, int m) {
        num = n * m;
        this -> n = n;
        this -> m = m;
    }
    
    vector<int> flip() {
        int random = (double)rand() / RAND_MAX * num;
        sort(v.begin(), v.end());
        for (int i = 0; i < v.size(); i++){
            if (random >= v[i]) random++;
            else break;
        }
        num--;
        v.push_back(random);
        return {random / m, random % m};
    }
    
    void reset() {
        num = n * m; 
        v = vector<int>();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(m, n);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */