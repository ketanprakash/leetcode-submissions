class Solution {
public:
    bool isDigit(char ch){
        if (ch == '0' || ch == '1' || ch == '2' || ch == '3' || ch == '4' || ch == '5' || ch == '6' || ch == '7' || ch == '8' || ch == '9') return true;
        return false;
    }

    int myAtoi(string s) {
        int n = s.size();
        int i = 0; 
        bool neg = false;

        long long num = 0;

        while (i < n && s[i] == ' '){
            i++;
        }
        
        if (i == n) return 0;

        if (s[i] == '-') {
            neg = true;
            i++;
        }
        else if (s[i] == '+'){
            i++;
        }

        for (;i < n; i++){
            if (isDigit(s[i])) {
                if (!neg && num * 10 + s[i] - '0' > INT_MAX) {
                    return INT_MAX;
                }
                else if (neg && -(num * 10 + s[i] - '0') < INT_MIN){
                    return INT_MIN;
                }
                num = num * 10 + s[i] - '0';
            }
            else break;
        }

        num = neg ? -num : num;
        return num;
    }
};