struct TrieNode {
    TrieNode *links[26];
    int flag; 

    TrieNode(){
        for (int i = 0; i < 26; i++) links[i] = nullptr;
        flag = 0;
    }
};

void insert(TrieNode* root, string &word){
    TrieNode *node = root; 

    for (int i = 0; i < word.size(); i++){
        if ((node -> links)[word[i] - 'a'] == nullptr){
            (node -> links)[word[i] - 'a'] = new TrieNode;
        }
        node = (node -> links)[word[i] - 'a'];
    }
    node -> flag = 1;
}

class Solution {
public:
    void dfs(vector<vector<char>> &board, int i, int j, TrieNode* root, vector<vector<bool>> &vis){
        int dr[] = {0, 0, 1, -1};
        int dc[] = {1, -1, 0, 0};

        if (root -> flag == 1){
            root -> flag = 2;
        }

        for (int drow = 0; drow < 4; drow++){
            int row = i + dr[drow], col = j + dc[drow];
            if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size()) continue;
            if ((root -> links)[board[row][col] - 'a'] == nullptr) continue;
            if (!vis[row][col]){
                vis[row][col] = true;
                dfs(board, row, col, (root -> links)[board[row][col] - 'a'], vis);
                vis[row][col] = false;
            }
        }
    }

    void findAns(TrieNode *root, string &str, vector<string> &ans){
        if (root -> flag == 2){
            cout << str << endl;
            ans.push_back(str);
        }
        for (int i = 0; i < 26; i++){
            if ((root -> links)[i] != nullptr){
                str.push_back(i + 'a');
                findAns((root -> links)[i], str, ans);
                str.pop_back();
            }
        }
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode *root = new TrieNode;
        vector<vector<bool>> vis(board.size(), vector<bool>(board[0].size()));

        for (string &word : words){
            insert(root, word);
        }

        for (int i = 0; i < board.size(); i++){
            for (int j = 0; j < board[0].size(); j++){
                if (!vis[i][j]){
                    vis[i][j] = true;
                    if ((root -> links)[board[i][j] - 'a'] != nullptr){
                        dfs(board, i, j, (root -> links)[board[i][j] - 'a'], vis);
                    }
                    vis[i][j] = false;
                }
            }
        }

        string str;
        vector<string> ans;
        findAns(root, str, ans);
        return ans;
    }
};