class Solution {
public:
    bool check(int freq[], int k){
        for (int i = 0; i < 26; i++){
            if (freq[i] != 0 && freq[i] != k) return false;
        }

        return true;
    }

    int countCompleteSubstrings(string word, int k) {
        int n = word.size();
        int ans = 0;
        vector<int> diffMoreThan1(word.size());
        for (int i = 0; i < word.size() - 1; i++){
            diffMoreThan1[i] = abs(word[i] - word[i + 1]) > 2;
        }
        
        for (int i = 1; i < word.size(); i++){
            diffMoreThan1[i] = diffMoreThan1[i - 1] + diffMoreThan1[i];
        }

        for (int l = 1 * k; l <= 26 * k; l += k){
            if (l > word.size()) break;
            int freq[26] = {0};
            int s = 0, e = s + l - 1; 
            for (int i = s; i <= e; i++){
                freq[word[i] - 'a']++;
            }
            if ((e - 1 >= 0 ? diffMoreThan1[e - 1] : 0) - (s - 1 >= 0 ? diffMoreThan1[s - 1] : 0) == 0 && check(freq, k)) {
                ans++;
            }
            while (e < n - 1){
                freq[word[++e] - 'a']++;
                freq[word[s++] - 'a']--;
                if ((e - 1 >= 0 ? diffMoreThan1[e - 1] : 0) - (s - 1 >= 0 ? diffMoreThan1[s - 1] : 0) == 0 && check(freq, k)) {
                    ans++;
                }
            }
        }

        return ans;
    }
};