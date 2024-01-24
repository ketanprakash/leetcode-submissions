class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int idx[26] = {0};
        for (int i = 0; i < order.size(); i++){
            idx[order[i] - 'a'] = i;
        }

        for (int i = 1; i < words.size(); i++){
            if (words[i - 1].size() > words[i].size() && words[i - 1].substr(0, words[i].size()) == words[i]) return false;
            for (int j = 0; j < min(words[i - 1].size(), words[i].size()); j++){
                if (idx[words[i - 1][j] - 'a'] < idx[words[i][j] - 'a']) break;
                if (idx[words[i - 1][j] - 'a'] > idx[words[i][j] - 'a']) return false;
            }
        }

        return true;
    }
};