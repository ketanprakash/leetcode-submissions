class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> m;
        m['I'] = 1;
        m['V'] = 5;
        m['X'] = 10;
        m['L'] = 50;
        m['C'] = 100;
        m['D'] = 500;
        m['M'] = 1000;
        int n = s.size();
        long long num = 0;
        for (int i = n - 1; i >= 0; i--){
            if (s[i] == 'V' && i - 1 >= 0 && s[i - 1] == 'I'){
                num += 4; 
                i--;
            }
            else if (s[i] == 'X' && i - 1 >= 0 && s[i - 1] == 'I'){
                num += 9;
                i--;
            }
            else if (s[i] == 'L' && i - 1 >= 0 && s[i - 1] == 'X'){
                num += 40;
                i--;
            }
            else if (s[i] == 'C' && i - 1 >= 0 && s[i - 1] == 'X'){
                num += 90;
                i--;
            }
            else if (s[i] == 'D' && i - 1 >= 0 && s[i - 1] == 'C'){
                num += 400;
                i--;
            }
            else if (s[i] == 'M' && i - 1 >= 0 && s[i - 1] == 'C'){
                num += 900;
                i--;
            }
            else {
                num += m[s[i]];
            }
        }

        return num;
    }
};