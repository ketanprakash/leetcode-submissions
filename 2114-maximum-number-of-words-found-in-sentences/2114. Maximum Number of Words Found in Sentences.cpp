class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int count, maxCount = 0;
        for (string &line : sentences){
            count = 0; 
            for (char &ch : line){
                if (ch == ' ') count++;
            }
            count++;
            maxCount = max(count, maxCount);
        }

        return maxCount;
    }
};