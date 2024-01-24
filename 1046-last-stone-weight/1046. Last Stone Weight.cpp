class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> q; 

        for (int i = 0; i < stones.size(); i++){
            q.push(stones[i]);
        }

        while (q.size() > 1){
            int x = q.top(); 
            q.pop(); 
            int y = q.top(); 
            q.pop(); 

            if (abs(y - x) != 0) q.push(abs(y - x));
        }

        if (q.empty()) return 0; 
        else return q.top();
    }
};