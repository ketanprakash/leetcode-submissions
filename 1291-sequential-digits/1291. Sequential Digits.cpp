class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        int lowSize = log10(low) + 1;
        int highSize = log10(high) + 1;

        int size = lowSize; 
        int num;
        vector<int> ans;
        while (size <= highSize){
            for (int i = 1; i <= 10 - size; i++){
                num = 0; 
                for (int j = i; j <= i + size - 1; j++){
                    num = num * 10 + j;
                }
                if (num >= low && num <= high) ans.push_back(num);
            }
            size++;
        }

        return ans;
    }
};