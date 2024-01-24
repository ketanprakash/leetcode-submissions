class Solution {
public:
    bool isValid(string s) {
        stack<char> st; 
        unordered_map<char, char> m; 
        m[')'] = '(';
        m['}'] = '{';
        m[']'] = '[';

        for (int i = 0; i < s.size(); i++){
            if (s[i] == '(' || s[i] == '{' || s[i] == '['){
                st.push(s[i]);
            }
            else {
                if (!st.empty() && m[s[i]] == st.top()) st.pop();
                else return false;
            }
        }

        return st.empty();
    }
};