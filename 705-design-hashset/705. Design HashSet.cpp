#define mod (int)1e3

class MyHashSet {
public:
    vector<vector<int>> hashTable;

    MyHashSet() {
        hashTable = vector<vector<int>>(mod);
    }
    
    int hash_function(int key){
        return key % mod; 
    }

    void add(int key) {
        int hash = hash_function(key);
        for (int i = 0; i < hashTable[hash].size(); i++){
            if (hashTable[hash][i] == key){
                return;
            }
        }
        hashTable[hash].push_back(key);
    }
    
    void remove(int key) {
        int hash = hash_function(key);

        for (int i = 0; i < hashTable[hash].size(); i++){
            if (hashTable[hash][i] == key){
                hashTable[hash][i] = hashTable[hash].back();
                hashTable[hash].pop_back();
                return;
            }
        }
    }
    
    bool contains(int key) {
        int hash = hash_function(key);
        for (int i = 0; i < hashTable[hash].size(); i++){
            if (hashTable[hash][i] == key) {
                return true;
            }
        }

        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */