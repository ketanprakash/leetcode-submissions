class Solution {
public:
    string reverseWords(string str) {
        int n = str.size();
        int s = 0; 
        int e = 0; 

        for (int i = 1; i <= n; i++){
            if (i == n || str[i] == ' '){
                reverse(str.begin() + s, str.begin() + e + 1);
                s = i + 1; e = i + 1;
                i++;
            }
            else e++;
        }

        return str;
    }
};