class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int countOne = 0;
        int res = 0;
        for (char &ch : s){
            if (ch == '1'){
                countOne++;
            }
            else {
                res = min(res + 1, countOne);
            }
        }

        return res;
    }
};