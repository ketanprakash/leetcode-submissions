class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if (s.size() < pow(2, k) + k - 1) return false;
        unordered_set<unsigned long long> st; 
        string str; 

        for (int i = 0; i < k; i++){
            str.push_back(s[i]);
        }

        unsigned long long x = stoull(str, 0, 2);
        st.insert(x);

        for (int i = k; i < s.size(); i++){
            x = x * 2 + s[i] - '0';
            x = x % (int)pow(2, k);
            st.insert(x);
        }
        return st.size() == pow(2, k);
    }
};