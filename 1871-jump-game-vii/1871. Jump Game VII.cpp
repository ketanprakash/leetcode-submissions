class Solution {
public:
    bool canReach(string str, int minJump, int maxJump) {
        queue<int> q; 
        int farthest = 0;
        q.push(0);

        while (!q.empty()){
            int node = q.front(); 
            q.pop(); 

            int s = max(farthest + 1, node + minJump);
            int e = min((int)str.size() - 1, node + maxJump);

            for (int i = s; i <= e; i++){
                if (str[i] == '0'){
                    farthest = max(i, farthest);
                    q.push(i);
                    if (i == str.size() - 1) return true;
                }
            }
        }

        return false;
    }
};