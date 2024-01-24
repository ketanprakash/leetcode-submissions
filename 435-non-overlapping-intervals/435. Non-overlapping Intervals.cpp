class Solution {
public:
    static bool cmp(vector<int> &a, vector<int> &b){
        return a[1] < b[1];
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size(); 
        sort(intervals.begin(), intervals.end(), cmp);
        
        vector<int> prev = intervals[0];
        int cnt = 0;
        for (int i = 1; i < n; i++){
            if (prev[1] > intervals[i][0]) {
                cnt++;
            }
            else  {
                prev = intervals[i];
            }
        }

        return cnt;
    }
};