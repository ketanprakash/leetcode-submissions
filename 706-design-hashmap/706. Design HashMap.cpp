#define mod (int)1e3

class MyHashMap {
public:
    vector<vector<pair<int, int>>> hashTable;

    MyHashMap() {
        hashTable = vector<vector<pair<int, int>>>(mod);
    }

    int hash_function(int key){
        return key % mod;
    }
    
    void put(int key, int value) {
        int hash = hash_function(key);

        for (int i = 0; i < hashTable[hash].size(); i++){
            if (hashTable[hash][i].first == key){
                hashTable[hash][i].second = value;
                return;
            }
        }
        hashTable[hash].push_back({key, value});
    }
    
    int get(int key) {
        int hash = hash_function(key);

        for (int i = 0; i < hashTable[hash].size(); i++){
            if (hashTable[hash][i].first == key){
                return hashTable[hash][i].second;
            }
        }

        return -1;
    }
    
    void remove(int key) {
        int hash = hash_function(key);

        for (int i = 0; i < hashTable[hash].size(); i++){
            if (hashTable[hash][i].first == key){
                hashTable[hash][i] = hashTable[hash].back();
                hashTable[hash].pop_back();
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */