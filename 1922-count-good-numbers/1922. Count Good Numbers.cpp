#define mod (int)(1e9 + 7)

class Solution {
public:
    int binExp(long long x, long long n){
        if (n == 0) return 1;
        if (n == 1) return x; 

        if (n % 2 == 0){
            return binExp(((x % mod) * (x % mod)) % mod, n / 2) % mod;
        }
        else {
            return ((binExp(x, n - 1) % mod) * (x % mod)) % mod;
        }
    }

    long long countGoodNumbers(long long n) {
        long long x = binExp(20, n / 2);

        if (n % 2 != 0) x = (long long)((x % mod) * (5)) % mod;

        return x;
    }
};