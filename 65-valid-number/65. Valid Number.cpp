class Solution {
public:
    bool isWholeNumber(string &str, int s, int e, int &size){
        if (e - s + 1 <= 0) return false;
        for (int i = s; i <= e; i++){
            if (str[i] < '0' || str[i] > '9') {return false;}
        }

        return true;
    }

    bool isInteger(string &str, int s, int e){
        if (e - s + 1 <= 0) return false;
        if (str[s] == '+' || str[s] == '-') return isWholeNumber(str, s + 1, e);
        else return isWholeNumber(str, s, e);
    }

    bool isDecimal(string &str, int s, int e){
        if (e - s + 1 <= 0) return false;

        for (int i = s; i <= e; i++){
            if (str[i] == '.') return isInteger(str, 0, i - 1) && isWholeNumber(str, i + 1, e);
        }

        return isInteger(str, s, e);
    }

    bool isValidNumber(string &str, int s, int e){
        for (int i = s; i <= e; i++){
            if (str[i] == 'e' || str[i] == 'E') return isDecimal(str, s, i - 1) && isInteger(str, i + 1, e);
        }

        return isDecimal(str, s, e);
    }

    bool isNumber(string s) {
        return isValidNumber(s, 0, s.size() - 1);
    }
};