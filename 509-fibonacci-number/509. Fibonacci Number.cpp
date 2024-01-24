class Solution {
public:
    vector<int> dp;

    Solution(){
        dp = vector<int>(31, -1);
    }

    int fibMemoization(int n){
        if (dp[n] != -1) return dp[n]; 
        if (n == 0 || n == 1) return dp[n] = n;
        return dp[n] = fib(n - 1) + fib(n - 2);
    }

    int fibTabulation(int n){
        dp[0] = 0; dp[1] = 1;

        for (int i = 2; i <= n; i++){
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        return dp[n];
    }

    int fibOptimized(int n){
        if (n == 0 || n == 1) return n;
        int prev2 = 0, prev1 = 1;

        for (int i = 2; i <= n; i++){
            int temp = prev1;
            prev1 = prev1 + prev2; 
            prev2 = temp;
        }

        return prev1;
    }

    int fib(int n) {
        return fibOptimized(n);
    }
};