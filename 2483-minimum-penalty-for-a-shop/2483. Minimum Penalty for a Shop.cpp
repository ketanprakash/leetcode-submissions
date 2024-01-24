class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size(); 
        vector<int> nBefore(n + 1), yAfter(n + 1);

        for (int i = n - 1; i >= 0; i--){
            yAfter[i] = yAfter[i + 1] + (customers[i] == 'Y' ? 1 : 0);
        }

        for (int i = 1; i <= n; i++){
            nBefore[i] = nBefore[i - 1] + (customers[i - 1] == 'N' ? 1 : 0);
        }

        int min_idx = -1; 
        int mn = INT_MAX; 
        for (int i = 0; i < n + 1; i++){
            if (mn > yAfter[i] + nBefore[i]){
                mn = yAfter[i] + nBefore[i];
                min_idx = i;
            }
        }

        return min_idx;
    }
};