class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        queue<int> q; 
        for (int i = 1; i <= 8; i++) q.push(i);

        int num;
        vector<int> ans;
        while (!q.empty()){
            num = q.front(); 
            q.pop(); 
            
            if (num >= low && num <= high) {
                ans.push_back(num);
            }

            if (num % 10 < 9 && num * 10 + num % 10 + 1 <= high){
                q.push(num * 10 + num % 10 + 1);
            }
        }
        sort(ans.begin(), ans.end());

        return ans;
    }
};