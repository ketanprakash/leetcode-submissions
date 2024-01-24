class RandomizedSet {
public:
    vector<int> v; 
    unordered_map<int, int> m;

    bool insert(int val) {
        if (m.count(val)) return false; 

        v.push_back(val);
        m[val] = v.size() - 1; 

        return true; 
    }
    
    bool remove(int val) {
        if (!m.count(val)) return false;

        int idx = m[val];
        if (idx == v.size() - 1){
            v.pop_back(); 
            m.erase(val);
        }
        else {
            v[idx] = v.back(); 
            v.pop_back();
            m.erase(val);
            m[v[idx]] = idx;
        }

        return true;
    }
    
    int getRandom() {
        int idx = (double)rand() / RAND_MAX * v.size(); 
        return v[idx];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */