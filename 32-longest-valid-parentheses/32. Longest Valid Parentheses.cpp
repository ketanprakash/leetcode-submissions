class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st; 

        for (int i = 0; i < s.size(); i++){
            if (s[i] == '(') st.push(i);
            else {
                if (!st.empty() && s[st.top()] == '(') st.pop();
                else st.push(i);
            }
        }

        int maxLen = 0;
        st.push(s.size());

        while (!st.empty()){
            int t = st.top(); 
            st.pop(); 

            maxLen = max(t - (st.empty() ? 0 : st.top() + 1), maxLen);
        }

        return maxLen;
    }
};