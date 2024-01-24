class Solution {
public:
    void sanitize(string &str){
        string ans;
        for (int i = 0; i < str.size(); i++){
            if (str[i] >= 'a' && str[i] <= 'z'){
                ans.push_back(str[i]);
            }
            else if (str[i] >= 'A' && str[i] <= 'Z'){
                ans.push_back(str[i] - 'A' + 'a');
            }
            else if (str[i] >= '0' && str[i] <= '9'){
                ans.push_back(str[i]);
            }
        }
        str = ans;
    }

    bool isPalindrome(string &str) {
        sanitize(str);
        int s = 0, e = str.size() - 1; 
        while (s < e){
            if (str[s] != str[e]){
                return false;
            }
            s++; e--;
        }

        return true;
    }
};