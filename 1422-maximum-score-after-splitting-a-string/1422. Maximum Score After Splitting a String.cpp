class Solution {
public:
    int maxScore(string s) {
        int count1 = 0, count0 = 0, maxScore = 0;
        for (char &ch : s) {
            if (ch == '1') count1++;
        }
        
        for (int i = 0; i < s.size() - 1; i++){
            if (s[i] == '1') count1--;
            else count0++;
            
            maxScore = max(count0 + count1, maxScore);
        }
        
        return maxScore;
    }
};