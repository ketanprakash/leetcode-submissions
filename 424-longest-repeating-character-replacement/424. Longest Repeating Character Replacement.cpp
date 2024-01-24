class Solution {
public:
    int characterReplacement(string &str, int num) {
        int ans = 0;
        int n = str.size();
        int s, e; 
        char ch;
        int k;

        for (int i = 0; i < 26; i++){
            k = num;
            ch = i + 'A';
            s = 0, e = -1; 

            while (e + 1 < n){
                e++;
                if (str[e] != ch){
                    k--;
                }
                if (k < 0) {
                    if (str[s] != ch) k++;
                    s++; 
                }
            }

            ans = max(ans, e - s + 1);
        }

        return ans;
    }
};