class Solution {
public:
    int helper(int base, int exp, int mod){
        if (base == 0) return 0;
        if (exp == 0) return 1;
        if (exp == 1) return base % mod;
        
        if (exp % 2 == 0) return helper(((base % mod) * (base % mod)) % mod, exp / 2, mod) % mod;
        else return ((helper(((base % mod) * (base % mod)) % mod, exp / 2, mod) % mod) * (base % mod)) % mod;
    }
    
    vector<int> getGoodIndices(vector<vector<int>>& variables, int target) {
        vector<int> ans;
        for (int i = 0; i < variables.size(); i++){
            int a = variables[i][0], b = variables[i][1], c = variables[i][2], m = variables[i][3];
            if (helper(helper(a, b, 10), c, m) == target) ans.push_back(i);
        }
        
        return ans;
    }
};