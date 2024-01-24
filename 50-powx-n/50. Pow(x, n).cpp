class Solution {
public:
    double myPow(double x, long long n) {
        if (x == 1) return 1;
        if (n < 0) return (double) 1 / myPow(x, -n);
        if (n == 0) return 1;
        if (n == 1) return x;
        if (n % 2 == 0) return myPow(x * x, n / 2);
        else return myPow(x * x, n / 2) * x;
    }
};