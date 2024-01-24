class Solution {
public:
    int helper(int num){
        int x = sqrt(num);
        
        while (x >= 1){
            if (num % x == 0) return x;
            x--;
        }
        
        return 1;
    }
    
    vector<int> closestDivisors(int num) {
        int x1 = helper(num + 1);
        int x2 = helper(num + 2);
        
        if ((num + 1)/ x1 - x1 <= (num + 2) / x2 - x2) return {x1, (num + 1)/ x1};
        else return {x2, (num + 2) / x2};
    }
};