class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
        vector<int> nge(nums.size());

        st.push(0);

        for (int i = 1; i < nums.size(); i++){
            while (!st.empty() && nums[i] > nums[st.top()]){
                nge[st.top()] = nums[i];
                st.pop();
            }
            st.push(i);
        }

        for (int i = 0; i < nums.size(); i++){
            while (!st.empty() && nums[i] > nums[st.top()]){
                nge[st.top()] = nums[i];
                st.pop();
            }
        }

        while (!st.empty()){
            nge[st.top()] = -1;
            st.pop();
        }

        return nge;
    }
};