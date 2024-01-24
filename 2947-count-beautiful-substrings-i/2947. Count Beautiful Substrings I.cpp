class Solution {
public:
    bool isVowel(char &ch){
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
    
    int beautifulSubstrings(string str, int k) {
        int vowels = 0; 
        
        int s, e;
        int ans = 0;
        for (int l = 2; l <= str.size(); l += 2){
            s = 0, e = s + l - 1;
            vowels = 0;
            for (int i = s; i <= e; i++) {
                if (isVowel(str[i])) vowels++;
            }
            
            if (2 * vowels == l && ((vowels % k) * (vowels % k)) % k == 0){ 
                ans++; 
            }
            
            while (e < str.size() - 1){
                if (isVowel(str[++e])) vowels++;
                if (isVowel(str[s++])) vowels--;
                
                if (2 * vowels == l && ((vowels % k) * (vowels % k)) % k == 0) {
                    ans++;
                }  
            }
        }
        
        return ans;
    }
}; 