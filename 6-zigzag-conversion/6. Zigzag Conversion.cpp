class Solution {
public:
    string convert(string s, int n) {
        if (n <= 1) return s;
        vector<string> v(n);

        int i = 0, j = 0; 

        while (i < s.size()){
            j = 0;
            while (j < n && i < s.size()){
                v[j].push_back(s[i]);
                i++;
                j++;
            }
            j = n - 2;
            while (j > 0 && i < s.size()){
                v[j].push_back(s[i]);
                j--;
                i++;
            }
        }

        string ans; 
        for (string &str : v) ans += str;

        return ans;
    }
};