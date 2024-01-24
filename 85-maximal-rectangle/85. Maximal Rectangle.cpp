class Solution {
public:
    vector<int> nextSmallerElement(vector<int> &arr){
        int n = arr.size();
        stack<int> st;
        vector<int> nse(n, n);

        for (int i = n - 1; i >= 0; i--){
            while (!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            nse[i] = st.empty() ? n : st.top();

            st.push(i);
        }
        
        return nse;
    }

    vector<int> previousSmallerElement(vector<int> &arr){
        int n = arr.size();
        stack<int> st; 
        vector<int> pse(n, -1);

        for (int i = n - 1; i >= 0; i--){
            while (!st.empty() && arr[st.top()] >= arr[i]){
                pse[st.top()] = i;
                st.pop();
            }

            st.push(i);
        }

        return pse;
    }

    int maxRectangleHist(vector<int> &arr){
        int n = arr.size();
        int pse = -1, nse = n;
        stack<int> st;
        int mx = 0;
        int idx;
        for (int i = n - 1; i >= -1; i--){
            while (!st.empty() && (i == -1 || arr[st.top()] >= arr[i])){
                pse = -1, nse = n;
                idx = st.top();
                st.pop();
                pse = i; 
                if (!st.empty()) nse = st.top();
                mx = max(mx, arr[idx] * (nse - pse - 1));
            }
            if (i != -1) st.push(i);
        }
        return mx;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int mx = 0;
        vector<int> v(matrix[0].size());


        for (int i = 0; i < matrix.size(); i++){
            for (int j = 0; j < v.size(); j++){
                v[j] = (matrix[i][j] - '0') == 0 ? 0 : v[j] + (matrix[i][j] - '0');
            }
            mx = max(mx, maxRectangleHist(v));
        }
        
        return mx;
    }
};