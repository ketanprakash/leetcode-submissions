class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size(); 
        unordered_map<int, int> nge;
        nge[nums2[n - 1]] = -1;
        stack<int> st; 
        st.push(n - 1);

        for (int i = n - 2; i >= 0; i--){
            while (!st.empty() && nums2[st.top()] <= nums2[i]){
                st.pop();
            }

            if (st.empty()) nge[nums2[i]] = -1;
            else nge[nums2[i]] = nums2[st.top()];

            st.push(i);
        }

        for (int i = 0; i < nums1.size(); i++) {
            nums1[i] = nge[nums1[i]];
        }

        return nums1;
    }
};