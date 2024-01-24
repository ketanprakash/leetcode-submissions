class Solution {
public:
    int num(int n){
        int ans = 0; 

        while (n){
            ans += (n % 10) * (n % 10);
            n = n / 10;
        }
        return ans;
    }
    bool isHappy(int n) {
        unordered_set<int> values; 

        while (true){
            if (n == 1) return true;
            values.insert(n);
            n = num(n);
            if (values.count(n)) return false;
            values.insert(n);
        }

        return true;
    }
};