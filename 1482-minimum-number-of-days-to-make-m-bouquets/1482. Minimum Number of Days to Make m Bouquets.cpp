class Solution {
public:
    bool check(vector<int> &bloomDay, int m, int k, int numberOfDays){
        int flowers = 0, bouquets = 0;
        for (int i = 0; i < bloomDay.size(); i++){
            if (bloomDay[i] <= numberOfDays) flowers++;
            else flowers = 0;

            if (flowers == k){
                bouquets++;
                flowers = 0;
            }
        }

        if (bouquets >= m) return true;

        return false;
    }

    int findMax(vector<int> &bloomDay){
        int maxm = bloomDay[0];
        for (int i = 0; i < bloomDay.size(); i++){
            maxm = max(maxm, bloomDay[i]);
        }

        return maxm;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        if (bloomDay.size() < (long long)m * k) return -1;

        int s = 1, e = findMax(bloomDay), mid, ans = -1;

        while (s <= e){
            mid = s + (e - s) / 2;

            if (check(bloomDay, m, k, mid)){
                ans = mid;
                e = mid - 1;
            }
            else {
                s = mid + 1;
            }
        }

        return ans;
    }
};