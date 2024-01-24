class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        int streamValue = 1;
        int diff;
        for (int i = 0; i < target.size(); i++){
            diff = target[i] - streamValue;

            for (int i = 0; i < diff; i++){
                ans.push_back("Push");
                ans.push_back("Pop");
            }
            ans.push_back("Push");
            streamValue = target[i] + 1;
        }

        return ans;
    }
};