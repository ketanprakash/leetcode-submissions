class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q; 
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> remaining; 
        vector<int> ans;

        for (int i = 0; i < servers.size(); i++){
            q.push({servers[i], i});
        }
        int time = 0;
        for (int i = 0; i < tasks.size(); i++){
            time = max(time, i);
            if (q.empty()) time = max(remaining.top().first, time);
            while (!remaining.empty() && time >= remaining.top().first){
                q.push({servers[remaining.top().second], remaining.top().second});
                remaining.pop();
            }

            ans.push_back(q.top().second);
            remaining.push({time + tasks[i], q.top().second});
            q.pop();
        }

        return ans;
    }
};