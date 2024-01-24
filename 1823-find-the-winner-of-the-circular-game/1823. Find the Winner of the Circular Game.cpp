class Solution {
public:
    int helper(int n, int k){
        if (n == 1) return 0;
        int i = (k - 1) % n;

        return (i + 1 + helper(n - 1, k)) % n;
    }

    int findTheWinner(int n, int k) {
        return helper(n, k) + 1;
    }
};