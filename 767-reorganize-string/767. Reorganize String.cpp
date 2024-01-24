class Solution {
public:
    string reorganizeString(string s) {
        int freq[26] = {0};
        for (int i = 0; i < s.size(); i++) freq[s[i] - 'a']++;
        priority_queue<pair<int, char>> q; 
        for (int i = 0; i < 26; i++) if (freq[i]) q.push({freq[i], i + 'a'});

        int idx = 0;
        while (!q.empty()){
            int count = q.top().first;
            char ch = q.top().second;
            q.pop();
            
            while (count--){
                if (idx >= s.size()) idx = 1;
                s[idx] = ch;
                idx += 2;
            }
        }

        for (int i = 1; i < s.size(); i++){
            if (s[i] == s[i - 1]) return "";
        }

        return s;
    }
};