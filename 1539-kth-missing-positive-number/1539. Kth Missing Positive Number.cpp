class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        if (arr[0] > k) return k;
        if (arr[n - 1] - n < k) return k + n;

        int s = 0, e = n - 2, m;

        while (s <= e){
            m = s + (e - s) / 2;

            if (arr[m] - (m + 1) < k && arr[m + 1] - (m + 2) >= k) return k + m + 1;

            if (arr[m] - (m + 1) < k) s = m + 1;
            else e = m - 1;
        }

        return 0;
    }
};