class Solution {
public:
    int minStickers(vector<string>& stickers, string target) {
        string freq; 
        string def; 

        for (int i = 0; i < 26; i++){
            freq.push_back(0);
            def.push_back(0);
        }

        for (char &ch : target){
            freq[ch - 'a']++;
        }
        queue<pair<string, int>> q; 
        q.push({freq, 0});
        unordered_set<string> vis;

        while (!q.empty()){
            auto [s, dst] = q.front();
            q.pop();

            if (s == def) return dst;
            for (auto &sticker : stickers){
                string freq = s;
                for (char &ch : sticker){
                    if (freq[ch - 'a']) freq[ch - 'a']--;
                }
                if (!vis.count(freq)) {
                    vis.insert(freq);
                    q.push({freq, dst + 1});
                }
            }
        }

        return -1;
    }
};