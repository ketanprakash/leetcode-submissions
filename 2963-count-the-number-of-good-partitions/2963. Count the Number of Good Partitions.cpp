class Solution {
public:    
    long long mod = 1e9 + 7;
    long long pow(long long base, long long exp, long long mod){
        if (base == 0) return 0;
        if (base == 1) return 1;
        if (exp == 0) return 1;
        if (exp == 1) return base % mod;
        
        if (exp % 2 == 0) return pow(((base % mod) * (base % mod)) % mod, exp / 2, mod) % mod;
        else return ((pow(((base % mod) * (base % mod)) % mod, exp / 2, mod) % mod) * (base % mod)) % mod;
    }
    
    long long numberOfGoodPartitions(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        unordered_map<int, int> lastIdx; 
        for (int i = 0; i < n; i++){
            lastIdx[nums[i]] = i;
        }
        int end = 0; 
        for (int i = 0; i < n; i++){
            end = max(end, lastIdx[nums[i]]);
            if (end == i){
                end = i + 1;
                count++;
            }
        }
        
        return pow(2, count - 1, mod);
    }
};