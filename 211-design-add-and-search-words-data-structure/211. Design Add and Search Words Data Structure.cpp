struct Node {
    Node *links[26];
    bool flag; 

    Node(){
        for (int i = 0; i < 26; i++) links[i] = nullptr;
        flag = false;
    }
};

class WordDictionary {
public:
    Node *root;
    WordDictionary() {
        root = new Node;
    }
    
    void addWord(string word) {
        Node *node = root;
        for (int i = 0; i < word.size(); i++){
            if ((node -> links)[word[i] - 'a'] == nullptr) (node -> links)[word[i] - 'a'] = new Node;
            node = (node -> links)[word[i] - 'a'];
        }

        node -> flag = true;
    }
    
    bool search(string word, Node *root){
        if (root == nullptr) return false;
        if (word == "") return root -> flag;

        if (word[0] == '.'){
            for (int i = 0; i < 26; i++){
                if (search(word.substr(1), (root -> links)[i])) return true;
            }
        }
        else {
            return search(word.substr(1), (root -> links)[word[0] - 'a']);
        }

        return false;
    }

    bool search(string word) {
        return search(word, root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */