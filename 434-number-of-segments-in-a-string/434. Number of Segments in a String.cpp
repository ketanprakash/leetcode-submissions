class Solution {
public:
    int countSegments(string s) {
        if (s.size() == 0) return 0;
        int n = s.size();
        int count = 0;

        for (int i = 1; i <= n; i++){
            if ((i == n || s[i] == ' ') && s[i - 1] != ' ') count++;
        }

        return count;
    }
};