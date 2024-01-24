class Solution {
public:
    int countSubstrings(string &str) {
        int n = str.size();
        int count = 0; 

        int s, e;
        for (int i = 0; i < n; i++){
            s = i, e = i; 
            while (s >= 0 && e < n && str[s] == str[e]){
                count++;
                s--;
                e++;
            }
            s = i, e = i + 1;
            while (s >= 0 && e < n && str[s] == str[e]){
                count++;
                s--;
                e++;
            }
        }

        return count;
    }
};