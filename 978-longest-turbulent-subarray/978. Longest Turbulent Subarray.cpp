class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        if (arr.size() == 0) return 0;

        int count = 1, maxCount = 1, x;

        x = 1;
        for (int i = 0; i < arr.size() - 1; i++){
            x *= -1;
            if (x * arr[i] > x * arr[i + 1]){
                count++;
            }
            else {
                count = 1;
            }
            maxCount = max(count, maxCount);
        }
        count = 1;
        x = -1;
        for (int i = 0; i < arr.size() - 1; i++){
            x *= -1;
            if (x * arr[i] > x * arr[i + 1]){
                count++;
            }
            else {
                count = 1;
            }
            maxCount = max(count, maxCount);
        }

        return maxCount;
    }
};