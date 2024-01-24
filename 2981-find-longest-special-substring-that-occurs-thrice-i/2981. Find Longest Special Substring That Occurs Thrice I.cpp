class Solution {
public:
    bool check(string &str, int size){
        int s = 0, e = s + size - 1; 
        
        int freq[26] = {0};
        int freq2[26] = {0};
        
        for (int i = s; i <= e; i++) {
            freq[str[i] - 'a']++;
        }
        
        for (int i = 0; i < 26; i++){
            if (accumulate(freq, freq + 26, 0) == freq[i]) freq2[i]++;
        }
        
        while (e < str.size() - 1){
            freq[str[s++] - 'a']--;
            freq[str[++e] - 'a']++;
            for (int i = 0; i < 26; i++){
                if (accumulate(freq, freq + 26, 0) == freq[i]) freq2[i]++;
            }
        }
        
        for (int i = 0; i < 26; i++) {
            if (freq2[i] >= 3) return true;
        }
        
        return false;
    }
    
    int maximumLength(string str) {
        if (str.size() <= 2) return -1;
        
        int s = 1, e = str.size() - 2, m;
        int ans = -1;
        
        while (s <= e){
            m = s + (e - s) / 2; 
            
            if (check(str, m)){
                ans = m; 
                s = m + 1;
            }
            else {
                e = m - 1;
            }
        }
        
        return ans;
    }
};