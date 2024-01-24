class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int n = arr.size();
        long long sum = 0, count = 0; 
        int i = 0, j;

        for (j = 0; j < k; j++){
            sum += arr[j];
        }

        if (sum / k >= threshold) count++;
        cout << sum / k << endl;
        while (j < n){
            sum = sum + arr[j] - arr[i];
            i++;
            if (sum / k >= threshold) count++;
            j++;

        }

        return count;
    }
};