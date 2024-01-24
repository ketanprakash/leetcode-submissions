class Solution {
public:
    int rev(int x){
        long long num = 0; 

        while (x){
            num = num * 10 + x % 10;
            x = x / 10;
        }

        return num;
    }

    bool isPalindrome(int x) {
        if (x < 0) return false;
        return rev(x) == x;
    }
};