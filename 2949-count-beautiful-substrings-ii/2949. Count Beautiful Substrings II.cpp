class Solution {
public:
    bool isVowel(char &ch){
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
    
    long long beautifulSubstrings(string str, int k) {
        int vowels = 0; 
        
        int s, e;
        int ans = 0;

        for (long long x = 1; sqrt(x * k) * 2 <= str.size(); x++){
            int a = sqrt(x * k);
            if (a * a != x * k) continue;
            
            int l = 2 * a;
            s = 0, e = s + l - 1;
            vowels = 0;
            
            for (int i = s; i <= e; i++) {
                if (isVowel(str[i])) vowels++;
            }
            
            if (vowels == a){ 
                ans++; 
            }
            
            while (e < str.size() - 1){
                if (isVowel(str[++e])) vowels++;
                if (isVowel(str[s++])) vowels--;
                
                if (vowels == a) {
                    ans++;
                }  
            }
        }
        
        return ans;
    }
}; 