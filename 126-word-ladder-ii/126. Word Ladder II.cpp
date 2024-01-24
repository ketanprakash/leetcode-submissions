class Solution {
public:
    void generateAns(int node, string beginWord, string endWord, vector<string> &wordList, vector<vector<int>> &parent, vector<string> &seq, vector<vector<string>> &ans){
        if (node == -1){
            seq.push_back(beginWord);
            reverse(seq.begin(), seq.end());
            ans.push_back(seq);
            reverse(seq.begin(), seq.end());
            seq.pop_back();
            return;
        }
        
        seq.push_back(wordList[node]);
        for (int p : parent[node]){
            generateAns(p, beginWord, endWord, wordList, parent, seq, ans);
        }
        seq.pop_back();
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size();
        unordered_map<string, int> idx;
        for (int i = 0; i < n; i++) idx[wordList[i]] = i;
        if (idx.find(endWord) == idx.end()) return {};
        idx[beginWord] = -1;

        vector<int> dist(n);
        queue<pair<int, int>> q;
        vector<vector<int>> parent(n);

        q.push({-1, 1});

        while (!q.empty()){
            int node = q.front().first;
            int distNode = q.front().second;
            q.pop();

            string str = node == -1 ? beginWord : wordList[node];
            
            for (int i = 0; i < str.size(); i++){
                char ch = str[i];
                for (int j = 0; j < 26; j++){
                    if (j + 'a' == ch) continue;
                    str[i] = j + 'a';
                    
                    if (idx.find(str) != idx.end()){
                        int child = idx[str];
                        if (child == -1) continue;
                        if (dist[child] == 0 || dist[child] > distNode + 1){
                            dist[child] = distNode + 1;
                            parent[child] = {node};
                            q.push({child, dist[child]});
                        }
                        else if (dist[child] == distNode + 1){
                            parent[child].push_back(node);
                        }
                    }
                }
                str[i] = ch;
            }
        }

        vector<vector<string>> ans;
        vector<string> seq;

        generateAns(idx[endWord], beginWord, endWord, wordList, parent, seq, ans);

        return ans;
    }
};