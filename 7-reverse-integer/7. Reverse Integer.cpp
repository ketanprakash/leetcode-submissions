class Solution {
public:
    int reverse(int x) {
        if (x == INT_MIN) return 0;
        int y = 0; 
        int num = x;
        x = abs(x);

        while (x){
            cout << x % 10 << endl;
            if (num > 0 && y > (INT_MAX - x % 10) / 10) return 0;
            else if (num < 0 && -y < (INT_MIN + (x % 10)) / 10) return 0;
            y = y * 10 + (x % 10);
            x = x / 10;
        }

        if (num < 0) y = -y;

        return y;
    }
};