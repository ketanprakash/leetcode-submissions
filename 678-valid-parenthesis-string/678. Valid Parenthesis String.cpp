class Solution {
public:
    bool checkValidString(string s) {
        int cmax = 0, cmin = 0; 

        for (int i = 0; i < s.size(); i++){
            if (s[i] == '('){
                cmax++; 
                cmin++;
            }
            else if (s[i] == ')'){
                cmax--; 
                cmin--;
            }
            else {
                cmax++;
                cmin--;
            }
            if (cmax < 0) return false;
            if (cmin < 0) cmin = 0;
        }

        return cmin == 0;
    }
};