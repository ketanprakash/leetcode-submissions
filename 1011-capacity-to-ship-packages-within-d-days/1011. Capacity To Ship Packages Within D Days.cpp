class Solution {
public:
    bool check(vector<int> &weights, int days, int capacity){
        int curr = 0, reqDays = 0;
        for (int i = 0; i < weights.size(); i++){
            if (weights[i] > capacity) return false;
            if (curr + weights[i] > capacity){
                reqDays++;
                curr = weights[i];
            }
            else curr += weights[i];
        }

        if (curr > 0) reqDays++;

        return reqDays <= days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int s = 0, e = accumulate(weights.begin(), weights.end(), 0), m, ans;

        while (s <= e){
            m = s + (e - s) / 2; 

            if (check(weights, days, m)){
                ans = m;
                e = m - 1;
            }
            else {
                s = m + 1;
            }
        }

        return ans;
    }
};