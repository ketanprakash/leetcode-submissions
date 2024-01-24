class Solution {
public:
    vector<int> dp;
    int helper(int idx, vector<int> &startTime, vector<int> &endTime, vector<int> &profit){
        if (idx == profit.size()) return 0;
        if (dp[idx] != -1) return dp[idx];
        int ans = 0;
        
        //not pick
        ans = max(ans, helper(idx + 1, startTime, endTime, profit));
        
        //pick
        int nextIdx = lower_bound(startTime.begin() + idx + 1, startTime.end(), endTime[idx]) - startTime.begin();
        ans = max(ans, helper(nextIdx, startTime, endTime, profit) + profit[idx]);
        
        return dp[idx] = ans;
    }
    
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
      
        int n = startTime.size();
        dp = vector<int>(n, -1);
        vector<vector<int>> v;
        
        for (int i = 0; i < n; i++){
            v.push_back({startTime[i], endTime[i], profit[i]});
        }
        
        sort(v.begin(), v.end());
        
        for (int i = 0; i < n; i++){
            startTime[i] = v[i][0];
            endTime[i] = v[i][1];
            profit[i] = v[i][2];
        }
        
        return helper(0, startTime, endTime, profit);
    }
};