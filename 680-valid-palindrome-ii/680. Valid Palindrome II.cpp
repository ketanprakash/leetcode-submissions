class Solution {
public:
    bool isPalindrome(string &str){
        int s = 0, e = str.size() - 1;
        while (s < e){
            if (str[s] != str[e]) return false;
            s++;
            e--;
        }
        return true;
    }

    bool validPalindrome(string &str) {
        int s = 0, e = str.size() - 1; 
        int count = 0;
        while (s < e){
            if (str[s] != str[e]){
                string str1 = str.substr(0, s) + str.substr(s + 1);
                string str2 = str.substr(0, e) + str.substr(e + 1);

                if (isPalindrome(str1) || isPalindrome(str2)) return true;
                else return false;
            }
            s++;
            e--;
        }

        return true;
    }
};