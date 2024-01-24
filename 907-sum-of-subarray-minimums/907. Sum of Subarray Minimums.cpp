class Solution {
public:
    int mod = 1e9 + 7;
    vector<int> prevSmallerElement(vector<int> &arr){
        stack<int> st;
        vector<int> pse(arr.size(), -1);
        
        for (int i = 0; i < arr.size(); i++){
            while (!st.empty() && arr[st.top()] > arr[i]){
                st.pop();
            }
            if (!st.empty()) pse[i] = st.top();
            st.push(i);
        }
        
        return pse;
    }
    
    vector<int> nextSmallerElement(vector<int> &arr){
        stack<int> st;
        vector<int> nse(arr.size(), arr.size());
        
        for (int i = arr.size() - 1; i >= 0; i--){
            while (!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            if (!st.empty()) nse[i] = st.top();
            
            st.push(i);
        }
        
        return nse;
    }
    
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        
        vector<int> nse = nextSmallerElement(arr);
        vector<int> pse = prevSmallerElement(arr);
        int ans = 0;
        for (int i = 0; i < arr.size(); i++){
            int left = i - pse[i] - 1;
            int right = nse[i] - i - 1;
            
            left = (left + 1) % mod;
            right = (right + 1) % mod;
            ans = (ans + ((long long)(left) * (right) * arr[i]) % mod) % mod;


        }
        
        return ans;
    }
};