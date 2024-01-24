class Solution {
public:
    string longestPalindrome(string &str) {
        int n = str.size();
        int maxLen = 0, max_s = -1;

        int s, e;
        for (int i = 0; i < n; i++){
            s = i, e = i;
            while (s >= 0 && e < n && str[s] == str[e]){
                if (e - s + 1 > maxLen){
                    maxLen = e - s + 1;
                    max_s = s; 
                }
                s--; e++;
            }

            s = i, e = i + 1;
            while (s >= 0 && e < n && str[s] == str[e]){
                if (e - s + 1 > maxLen){
                    maxLen = e - s + 1;
                    max_s = s; 
                }
                s--; e++;
            }
        }

        return str.substr(max_s, maxLen);
    }
};