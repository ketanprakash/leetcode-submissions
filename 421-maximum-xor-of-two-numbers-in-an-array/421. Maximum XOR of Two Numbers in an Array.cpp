struct Node{
    Node* links[2];
    bool flag;

    Node(){
        links[0] = links[1] = nullptr;
        flag = false;
    }

    void put(int bit){
        links[bit] = new Node;
    }

    bool contains(int bit){
        return !(links[bit] == nullptr);
    }

    Node* get(int bit){
        return links[bit];
    }

    bool getEnd(){
        return flag;
    }

    void setEnd(){
        flag = true;
    }
};

class Trie{
    public: 
    Node* root; 

    Trie(){
        root = new Node; 
    }

    void insert(int num){
        Node* node = root; 

        for (int i = 31; i >= 0; i--){
            int bit = (num >> i) & 1;
            
            if (!(node -> contains(bit))){
                node -> put(bit);
            }
            node = node -> get(bit);
        }
        node -> setEnd();
    }

    int maxXor(int num){
        int ans = 0; 
        Node* node = root;

        for (int i = 31; i >= 0; i--){
            int bit = (num >> i) & 1;

            if (node -> contains(!bit)){
                ans = ans | (1 << i);
                node = node -> get(!bit);
            }
            else {
                node = node -> get(bit);
            }
        }

        return ans;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie *trie = new Trie;
        int maxm = 0; 

        for (int i = 0; i < nums.size(); i++){
            trie -> insert(nums[i]);
        }

        for (int i = 0; i < nums.size(); i++){
            maxm = max(trie -> maxXor(nums[i]), maxm);
        }

        return maxm;
    }
};