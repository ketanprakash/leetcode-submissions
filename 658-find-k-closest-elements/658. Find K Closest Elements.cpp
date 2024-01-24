class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        long long total = 0;
        
        for (int i = 0; i < k; i++){
            total += abs(arr[i] - x);
        }

        int min_s = 0, min_e = k - 1, mn = total;

        for (int i = k; i < arr.size(); i++){
            total -= abs(arr[i - k] - x);
            total += abs(arr[i] - x);

            if (total < mn){
                mn = total;
                min_s = i - k + 1;
                min_e = i;
            }
        }

        vector<int> v; 

        for (int i = min_s; i <= min_e; i++) v.push_back(arr[i]);

        return v;
    }
};