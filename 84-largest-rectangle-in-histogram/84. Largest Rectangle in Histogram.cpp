class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        st.push(0);
        int maxArea = 0;
        for (int i = 1; i < n; i++){
            while (!st.empty() && heights[st.top()] >= heights[i]){
                int ele = heights[st.top()];
                st.pop();
                int ps = -1, ns = i;

                if (!st.empty()) ps = st.top();
                maxArea = max(maxArea, ele * (ns - ps - 1));
            }

            st.push(i);
        }

        while (!st.empty()){
            int ele = heights[st.top()];
            st.pop();

            int ps = -1, ns = n;

            if (!st.empty()) ps = st.top();

            maxArea = max(maxArea, ele * (ns - ps - 1));
        }

        return maxArea;
    }
};