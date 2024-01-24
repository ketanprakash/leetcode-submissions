class Solution {
public:
    bool check(int x, int y, int x1, int y1, int r){
        double dist = sqrt(((double)x - x1) * (x - x1) + ((double)y - y1) * (y - y1));

        if (dist <= r) return true;
        return false;
    }

    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        queue<int> q;

        vector<int> vis;

        int maxCount = 0;

        
        for (int i = 0; i < bombs.size(); i++){
            vis = vector<int>(n);

            q.push(i);
            int count = 0;
            while (!q.empty()){
                int bomb = q.front();
                q.pop();
                if (vis[bomb]) continue;
                vis[bomb] = 1;
                count++;

                int x = bombs[bomb][0], y = bombs[bomb][1], r = bombs[bomb][2];

                for (int j = 0; j < n; j++){
                    int x1 = bombs[j][0], y1 = bombs[j][1];

                    if (check(x, y, x1, y1, r)) q.push(j);
                }
            }
            maxCount = max(count, maxCount);
        }

        return maxCount;
    }
};