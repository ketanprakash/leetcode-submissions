class RandomizedCollection {
public:
    unordered_map<int, int> m;
    
    bool insert(int val) {
        bool ans = !m.count(val);
        m[val]++;

        return ans;
    }
    
    bool remove(int val) {
        if (!m.count(val)) return false;

        m[val]--; 
        if (m[val] == 0) m.erase(val);

        return true;
    }
    
    int getRandom() {
        int idx = (*(m.begin())).first;
        int freq = m[idx];
        m.erase(idx); 
        m[idx] = freq;

        return idx;
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */