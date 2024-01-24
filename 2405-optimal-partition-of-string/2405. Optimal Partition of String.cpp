class Solution {
public:
    int partitionString(string s) {
        int count = 0; 
        unordered_set<char> st;

        for (int i = 0; i < s.size(); i++){
            if (st.count(s[i])){
                count++; 
                st.clear();
            }
            st.insert(s[i]);
        }
        return count + 1;
    }

};