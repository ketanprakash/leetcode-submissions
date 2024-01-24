class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        queue<pair<string, int>> q; 
        unordered_set<string> vis;
        for (int i = 0; i < deadends.size(); i++) vis.insert(deadends[i]);

        q.push({"0000", 0});
        string node, child; 
        int moves;

        while (!q.empty()){
            node = q.front().first; 
            moves = q.front().second;
            q.pop(); 
            if (node == target) return moves;
            if (vis.count(node)) continue;
            vis.insert(node);

            for (int i = 0; i < node.size(); i++){
                child = node;
                child[i]++;
                if (child[i] > '9') child[i] = '0';
                q.push({child, moves + 1});
                child = node;
                child[i]--;
                if (child[i] < '0') child[i] = '9';
                q.push({child, moves + 1});
            }
        }

        return -1;
    }
};