class Solution {
public:
    int totalMoney(int n) {
        int rem = n % 7;
        n = n / 7;

        return (n * (n - 1) / 2 * 7 + 28 * n + rem * (rem + 1) / 2 + n * rem);
    }
};