class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st; 

        int b, a;
        for (string &s : tokens){
            if (s == "+"){
                b = st.top(); 
                st.pop(); 
                a = st.top();
                st.pop();

                st.push(a + b);
            }
            else if (s == "-"){
                b = st.top(); 
                st.pop(); 
                a = st.top();
                st.pop();

                st.push(a - b);
            }
            else if (s == "*"){
                b = st.top(); 
                st.pop(); 
                a = st.top();
                st.pop();

                st.push(a * b);
            }
            else if (s == "/"){
                b = st.top(); 
                st.pop(); 
                a = st.top();
                st.pop();

                st.push(a / b);
            }
            else st.push(stoi(s));
        }

        return st.top();
    }
};