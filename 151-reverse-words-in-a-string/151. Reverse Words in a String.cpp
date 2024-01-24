class Solution {
public:
    void reverse(string &s, int l, int r){
        while (l < r){
            swap(s[l], s[r]);
            l++;
            r--;
        }
    }

    string reverseWords(string s) {
        reverse(s, 0, s.size() - 1);

        int l = 0;
        string str;
        int n = s.size();
        for (int i = 0; i <= s.size(); i++){
            if (i == n || s[i] == ' ') {
                if (l < i){
                    int l1 = str.size();
                    for (int j = l; j < i; j++){
                        str.push_back(s[j]);
                    }
                    str.push_back(' ');
                    reverse(str, l1, str.size() - 2);
                }
                l = i + 1;
            }
        }

        for (int i = str.size() - 1; i >= 0; i--){
            if (str[i] == ' ') {
                str.pop_back();
            }
            else break;
        }

        return str;
    }
};