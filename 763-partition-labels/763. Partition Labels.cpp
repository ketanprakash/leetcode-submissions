class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();
        int lastIdx[26];
        for (int i = 0; i < 26; i++) lastIdx[i] = -1;
        
        for (int i = 0; i < n; i++){
            lastIdx[s[i] - 'a'] = i;
        }

        vector<int> ans; 
        int start = 0;
        int end = 0;

        for (int i = 0; i < n; i++){
            end = max(end, lastIdx[s[i] - 'a']);

            if (end == i){
                ans.push_back(end - start + 1);
                start = i + 1;
            }
        }

        return ans;
    }
};