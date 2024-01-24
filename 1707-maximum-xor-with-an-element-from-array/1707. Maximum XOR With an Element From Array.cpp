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
        bool flag = false; 

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
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        Trie *trie = new Trie;
        vector<int> ans(queries.size());
        sort(nums.begin(), nums.end());

        vector<pair<pair<int, int>, int>> offlineQueries; 
        for (int i = 0; i < queries.size(); i++){
            offlineQueries.push_back({{queries[i][1], queries[i][0]}, i});
        }

        sort(offlineQueries.begin(), offlineQueries.end());

        int i = 0;
        for (auto p : offlineQueries){
            int m = p.first.first;
            int x = p.first.second;
            int idx = p.second;

            if (m < nums[0]) ans[idx] = -1;
            else {
                for (;i < nums.size() && nums[i] <= m; i++){
                    trie -> insert(nums[i]);
                }

                ans[idx] = trie -> maxXor(x);
            }
        }

        return ans;
    }
};