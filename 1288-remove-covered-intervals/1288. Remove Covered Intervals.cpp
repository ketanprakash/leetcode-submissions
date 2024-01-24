class Solution {
public:
    static bool cmp(vector<int> &a, vector<int> &b){
        return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]);
    }

    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        vector<vector<int>> ans = {intervals[0]};

        for (int i = 1; i < intervals.size(); i++){
            if (ans.back()[1] < intervals[i][1]){
                ans.push_back(intervals[i]);
            }
        }

        return ans.size();
    }
};