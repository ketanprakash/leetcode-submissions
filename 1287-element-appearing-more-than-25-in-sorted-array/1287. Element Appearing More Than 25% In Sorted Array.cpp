class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size();
        
        int count = 0;
        for (int i = 0; i < n; i++){
            count++;
            if (i == n - 1 || arr[i + 1] != arr[i]){
                if (count > n / 4) return arr[i];
                count = 0;
            }
        }

        return -1;
    }
};