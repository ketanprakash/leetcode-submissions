class Solution {
public:
    void generate(int open, int close, int n, string &ans, vector<string> &permutations){
        if (open == n && close == n){
            permutations.push_back(ans);
            return;
        }
        if (open < n){
            ans.push_back('(');
            generate(open + 1, close, n, ans, permutations);
            ans.pop_back();
        }
        if (close < open){
            ans.push_back(')');
            generate(open, close + 1, n, ans, permutations);
            ans.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        string ans;
        vector<string> permutations;

        generate(0, 0, n, ans, permutations);

        return permutations;
    }
};