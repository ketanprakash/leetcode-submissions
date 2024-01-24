class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.size(); 
        while (n >= 1 && (num[n - 1] - '0') % 2 == 0){
            n--;
        }
        return num.substr(0, n);
    }
};