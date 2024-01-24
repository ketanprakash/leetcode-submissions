class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int prev = 0;
        int count;
        int ans = 0;

        
        for (auto &str : bank){
            count = 0;
            for (char &ch : str){
                count += ch - '0';
            }
            ans += prev * count;
            if (count) prev = count;
        }
        
        return ans;
    }
};