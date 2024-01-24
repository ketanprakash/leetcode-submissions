class Solution {
public:
    vector<string> findRepeatedDnaSequences(string &s) {
        if (s.size() < 10) return {};
        unordered_set<string> st; 
        unordered_set<string> ans;
        vector<string> v;
        string str;
        
        for (int i = 0; i < 10; i++){
            str.push_back(s[i]);
        }
        st.insert(str);

        for (int i = 10; i < s.size(); i++){
            str.push_back(s[i]);
            str = str.substr(1);
            if (st.count(str)) ans.insert(str);
            else st.insert(str);
        }

        for (auto i : ans){
            v.push_back(i);
        }
        return v;
    }
};