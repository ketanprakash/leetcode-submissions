class Solution {
public:
    bool f(vector<int> &v1, vector<int> &v2){
        return v1[0] < v2[0];
    }

    vector<int> getOrder(vector<vector<int>>& tasks) {
        for (int i = 0; i < tasks.size(); i++){
            tasks[i].push_back(i);
        }

        sort(tasks.begin(), tasks.end());

        long long time = tasks[0][0];
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        int i = 0;
        vector<int> v;
        while (!q.empty() || i < tasks.size()){
            if (q.empty() && time < tasks[i][0]) time = tasks[i][0];
            while (i < tasks.size() && time >= tasks[i][0]) {
                q.push({tasks[i][1], tasks[i][2]});
                i++;
            }

            v.push_back(q.top().second);
            time += (long long)q.top().first;
            q.pop();
        }

        return v;
    }
};