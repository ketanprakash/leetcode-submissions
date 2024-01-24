class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>> st; 

        for (int i = 0; i < s.size(); i++){
            if (!st.empty() && st.top().first == s[i]){
                st.top().second++;

                if (st.top().second == k){
                    st.pop();
                }
            }
            else {
                st.push({s[i], 1});
            }
        }
        s.clear();

        while (!st.empty()){
            while (st.top().second--){
                s.push_back(st.top().first);
            }
            st.pop();
        }

        reverse(s.begin(), s.end());
        return s;
    }
};