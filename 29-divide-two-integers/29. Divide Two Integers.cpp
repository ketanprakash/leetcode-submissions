class Solution {
public:
    int sgn(int x){
        if (x == 0) return 0;
        if (x == INT_MIN) return -1;
        if (x == INT_MAX) return 1;
        return x / abs(x);
    }

    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;
        if (dividend == INT_MIN && divisor == 1) return INT_MIN;
        if (dividend == INT_MAX && divisor == 1) return INT_MAX;
        if (dividend == INT_MAX && divisor == -1) return -INT_MAX;
        int x, y; 

        x = dividend < 0 ? dividend : -dividend;
        y = divisor < 0 ? divisor : -divisor; 

        int count = 0;
        while (x < 0){
            count++;
            x -= y;
        }

        if (x > 0) count--;

        if (sgn(dividend) * sgn(divisor) < 0) count = -count;
        return count;
    }
};