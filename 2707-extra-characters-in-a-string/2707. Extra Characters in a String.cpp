struct TrieNode{
    TrieNode *links[26];
    bool flag;

    TrieNode(){
        for (int i = 0; i < 26; i++) links[i] = nullptr;
        flag = false;
    }
};

void insert(TrieNode *root, string &word){
    TrieNode *node = root;
    for (int i = 0; i < word.size(); i++){
        if ((node -> links)[word[i] - 'a'] == nullptr) {
            (node -> links)[word[i] - 'a'] = new TrieNode;
        }
        node = (node -> links)[word[i] - 'a'];
    }

    node -> flag = true;
}

class Solution {
public:
    int helper(string &str, unordered_set<string> &s, int start, vector<int> &dp){
        if (start == str.size()) return 0;
        if (dp[start] != -1) return dp[start];
        string temp;
        int ans = -1;
        for (int i = start; i < str.size(); i++){
            temp.push_back(str[i]);

            if (s.count(temp)) {
                ans = ans == -1 ? helper(str, s, i + 1, dp) : min(ans, helper(str, s, i + 1, dp));
            }
            else {
                ans = ans == -1 ? helper(str, s, i + 1, dp) + temp.size() : min(ans, helper(str, s, i + 1, dp) + (int)temp.size());
            }
        }
        return dp[start] = ans;
    }

    int helper(string &str, TrieNode *root, int start, vector<int> &dp){
        if (start == str.size()){
            return 0;
        }
        if (dp[start] != -1) return dp[start];
        TrieNode *node = root; 
        int ans = -1;

        for (int i = start; i < str.size(); i++){
            if (node == nullptr){
                ans = ans == -1 ? helper(str, root, i + 1, dp) + i - start + 1 : min(ans, helper(str, root, i + 1, dp) + i - start + 1);
            }
            else {
                node = (node -> links)[str[i] - 'a'];
                if (node == nullptr || node -> flag == false){
                    ans = ans == -1 ? helper(str, root, i + 1, dp) + i - start + 1 : min(ans, helper(str, root, i + 1, dp) + i - start + 1);
                }
                else {
                    ans = ans == -1 ? helper(str, root, i + 1, dp) : min(ans, helper(str, root, i + 1, dp));
                }
            }
        }

        return dp[start] = ans;
    }

    int minExtraChar(string str, vector<string>& dictionary) {
        vector<int> dp(str.size(), -1);
        TrieNode *root = new TrieNode;
        
        for (int i = 0; i < dictionary.size(); i++){
            insert(root, dictionary[i]);
        }

        return helper(str, root, 0, dp);
    }
};