bool comparator(vector<int> &v1, vector<int> &v2){
    return v1[1] < v2[1];
}

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        sort(trips.begin(), trips.end(), comparator);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

        for (int i = 0; i < trips.size(); i++){
            while (!q.empty() && trips[i][1] >= q.top().first){
                capacity += q.top().second;
                q.pop();
            }

            if (capacity < trips[i][0]) return false;
            capacity -= trips[i][0];
            q.push({trips[i][2], trips[i][0]});
        }

        return true;
    }
};