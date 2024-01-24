class Solution {
public:
    static int setBits(int n){
        int count = 0;
        while (n){
            count++;
            n &= n - 1;
        }
        return count;
    }
    
    static bool f(int &a, int &b){
        if (setBits(a) < setBits(b)) return true;
        
        if (setBits(a) == setBits(b)) return a < b;
        
        return false;
    }
    
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), f);
        
        return arr;
    }
};