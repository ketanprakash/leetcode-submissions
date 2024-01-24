class Solution {
public:
    int numberOfSubstrings(string &str) {
        int s = 0, e = 0, c1 = 0, c2 = 0, c3 = 0; 
        int ans = 0;

        while (e < str.size()){
            c1 += (str[e] == 'a') ? 1 : 0; 
            c2 += (str[e] == 'b') ? 1 : 0; 
            c3 += (str[e] == 'c') ? 1 : 0;

            while (c1 - (str[s] == 'a') >= 1 && c2 - (str[s] == 'b') >= 1 && c3 - (str[s] == 'c') >= 1){
                c1 -= (str[s] == 'a') ? 1 : 0; 
                c2 -= (str[s] == 'b') ? 1 : 0; 
                c3 -= (str[s] == 'c') ? 1 : 0;
                s++;
            }

            if (c1 >= 1 && c2 >= 1 && c3 >= 1) ans += s + 1;
            e++;
        }

        return ans;
    }
};