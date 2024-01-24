class Solution {
public:
    int integerBreak(int n) {
        long long ans = 0; 

        for (int k = 2; k <= n; k++){
            ans = max(ans, (long long)pow(n / k, k - n % k) * (long long)pow(n / k + 1, n % k));
        }

        return ans;
    }
};