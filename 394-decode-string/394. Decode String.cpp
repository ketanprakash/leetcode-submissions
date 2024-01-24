class Solution {
public:
    string decodeString(string s) {
        string str; 
        stack<string> st;

        for (int i = 0; i < s.size(); i++){
            if (s[i] >= '0' && s[i] <= '9'){
                if (str.size() == 0 || (str.back() >= '0' && str.back() <= '9')){
                }
                else {
                    if (st.empty() || st.top() == "[") st.push(str);
                    else st.top().insert(st.top().end(), str.begin(), str.end());
                    str = "";
                }
                str.push_back(s[i]);
            }
            else if (s[i] == '['){
                st.push(str);
                str = "";
                st.push("[");
            }
            else if (s[i] == ']'){
                if (str.size() != 0) {
                    if (st.empty() || st.top() == "[") st.push(str);
                    else st.top().insert(st.top().end(), str.begin(), str.end());
                    str = "";
                }
                string a = st.top();
                st.pop();
                if (st.top() == "[") st.pop();
                cout << st.top() << endl;
                int num = stoi(st.top());
                // int num = 10;
                st.pop();
                if (st.empty() || st.top() == "[" || (st.top().back() >= '0' && st.top().back() <= '9')) st.push("");

                while (num--){
                    st.top().insert(st.top().end(), a.begin(), a.end());
                }
            }
            else {
                str.push_back(s[i]);
            }
        }
        if (st.empty()) st.push("");
        if (str.size() != 0) st.top().insert(st.top().end(), str.begin(), str.end());
        str = "";

        return st.top();
    }
};