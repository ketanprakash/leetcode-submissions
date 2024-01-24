class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        reverse(popped.begin(), popped.end());
        stack<int> st; 

        for (int i = 0; i < pushed.size(); i++){
            while (!st.empty() && st.top() == popped.back()){
                st.pop();
                popped.pop_back();
            }
            st.push(pushed[i]);
        }
        while (!st.empty() && st.top() == popped.back()){
            st.pop();
            popped.pop_back();
        }

        return st.empty();
    }
};