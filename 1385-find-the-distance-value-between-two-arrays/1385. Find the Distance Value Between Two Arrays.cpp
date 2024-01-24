class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr1.begin(), arr1.end());
        sort(arr2.begin(), arr2.end());

        int count = 0;
        for (int i = 0; i < arr1.size(); i++){
            int idx = lower_bound(arr2.begin(), arr2.end(), arr1[i]) - arr2.begin();

            if ((idx < arr2.size() && abs(arr1[i] - arr2[idx]) <= d) || (idx - 1 >= 0 && abs(arr1[i] - arr2[idx - 1]) <= d)) continue;
            count++;
        }

        return count;
    }
};