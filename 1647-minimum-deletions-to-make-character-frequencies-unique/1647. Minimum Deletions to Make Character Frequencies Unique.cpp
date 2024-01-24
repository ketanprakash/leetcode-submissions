class Solution {
public:
    int minDeletions(string s) {
        int freq[26] = {0};
        priority_queue<int> q;

        for (int i = 0; i < s.size(); i++){
            freq[s[i] - 'a']++;
        }

        for (int i = 0; i < 26; i++){
            if (freq[i] != 0) q.push(freq[i]);
        }

        int count = 0; 

        while (!q.empty()){
            int f = q.top(); 
            q.pop(); 
            while (!q.empty() && f == q.top()){
                count++;
                if (q.top() - 1 > 0) q.push(q.top() - 1);
                q.pop();
            }
        }

        return count;
    }
};