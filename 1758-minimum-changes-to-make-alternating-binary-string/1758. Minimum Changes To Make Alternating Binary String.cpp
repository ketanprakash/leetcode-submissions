class Solution {
public:
    int minOperations(string s) {
        int x = 0;
        int ans = INT_MAX;
        int count = 0;
        
        for (char ch : s){
            if (ch != x + '0') count++;
            x = !x;
        }
        
        ans = min(count, ans);
        
        x = 1, count = 0;
        for (char ch : s){
            if (ch != x + '0') count++;
            x = !x;
        }
        ans = min(ans, count);
        
        return ans;
    }
};