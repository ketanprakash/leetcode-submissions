class Solution {
public:
    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
        sort(access_times.begin(), access_times.end());
        vector<string> ans;

        int s = 0, e = 2;
        while (e < access_times.size()){
            if (access_times[s][0] == access_times[e][0] && stoi(access_times[e][1]) - stoi(access_times[s][1]) < 100){
                if (ans.size() == 0 || ans.back() != access_times[s][0]) ans.push_back(access_times[s][0]);
            }
            s++;
            e++;
        }

        return ans;
    }
};