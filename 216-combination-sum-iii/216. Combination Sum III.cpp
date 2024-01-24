class Solution {
public:
    void helper(int k, int n, int num, vector<int> &curr, vector<vector<int>> &ans){
        if (k == 0 && n == 0) {
            ans.push_back(curr);
            return;
        }
        
        if (k == 0 || n == 0) return;

        for (int i = num; i <= 9; i++){
            curr.push_back(i);
            helper(k - 1, n - i, i + 1, curr, ans);
            curr.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> curr;

        vector<vector<int>> ans;

        helper(k, n, 1, curr, ans);

        return ans;
    }
};