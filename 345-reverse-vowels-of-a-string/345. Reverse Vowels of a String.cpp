class Solution {
public:
    string reverseVowels(string &str) {
        int s = 0, e = str.size() - 1; 

        unordered_set<char> st;
        st.insert('a'), st.insert('e'), st.insert('i'), st.insert('o'), st.insert('u');
        st.insert('A'), st.insert('E'), st.insert('I'), st.insert('O'), st.insert('U');

        while (s < e){
            while (s < e && st.count(str[s]) == 0) s++;
            while (s < e && st.count(str[e]) == 0) e--;

            swap(str[s], str[e]);
            s++;
            e--;
        }

        return str;
    }
};