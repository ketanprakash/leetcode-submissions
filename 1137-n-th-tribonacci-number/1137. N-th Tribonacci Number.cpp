class Solution {
public:
    int tribonacci(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        if (n == 2) return 1;

        int a = 0, b = 1, c = 1;
        int tmpB, tmpC;
        for (int i = 3; i <= n; i++){
            tmpC = c;
            tmpB = b;
            c = c + b + a;
            b = tmpC;
            a = tmpB;
        }
        return c;
    }
};