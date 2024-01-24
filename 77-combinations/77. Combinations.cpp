class Solution {
public:
    void combine(int s, int e, int k, vector<int> &curr, vector<vector<int>> &ans){
        if (k == 0){
            ans.push_back(curr);
            return;
        }
        if (s > e) return;

        for (int i = s; i <= e; i++){
            curr.push_back(i);
            combine(i + 1, e, k - 1, curr, ans);
            curr.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<int> curr; 
        vector<vector<int>> ans;

        combine(1, n, k, curr, ans);

        return ans;
    }
};