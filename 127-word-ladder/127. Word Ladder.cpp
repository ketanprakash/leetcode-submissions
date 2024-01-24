class Solution {
public:
    int ladderLength(string &beginWord, string &endWord, vector<string>& wordList) {
        int n = wordList.size();
        unordered_map<string, int> idx;
        for (int i = 0; i < n; i++) idx[wordList[i]] = i;
        if (idx.find(endWord) == idx.end()) return 0;
        idx[beginWord] = -1;

        vector<int> dist(n);
        queue<pair<int, int>> q;

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
                            q.push({child, dist[child]});
                        }
                    }
                }
                str[i] = ch;
            }
        }

        return dist[idx[endWord]];
    }
};