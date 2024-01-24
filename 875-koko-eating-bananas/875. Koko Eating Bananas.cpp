class Solution {
public:
    bool check(vector<int> &piles, int h, int speed){
        int time = 0;
        for (int i = 0; i < piles.size(); i++){
            time += ceil((double)piles[i] / speed);
        }

        return time <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int s = 1, e = INT_MAX, m, ans;

        while (s <= e){
            m = s + (e - s) / 2;

            if (check(piles, h, m)){
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