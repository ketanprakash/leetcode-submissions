class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        string str;
        for (int i = 0; i < path.size(); i++){
            if (path[i] == '/'){
                if (str.size() == 0) continue;
                if (str == "."){
                    str = "";
                }
                else if (str == ".."){
                    str = "";
                    if (!st.empty()) st.pop();
                }
                else {
                    st.push(str);
                    str = "";
                }
            }
            else {
                str.push_back(path[i]);
            }
        }

        if (str.size() != 0) {
            if (str == "."){
                str = "";
            }
            else if (str == ".."){
                str = "";
                if (!st.empty()) st.pop();
            }
            else {
                st.push(str);
                str = "";
            }
        }
        string ans;

        while (!st.empty()){
            reverse(st.top().begin(), st.top().end());
            ans.insert(ans.end(), st.top().begin(), st.top().end());
            ans.push_back('/');
            st.pop();
        }
        if (ans.size() == 0 || ans.back() != '/') ans.push_back('/');
        reverse(ans.begin(), ans.end());
        return ans;
    }
};