class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int freq[26] = {0};
        int max_freq = 0, max_freq_count = 0, cycle = n + 1;

        for (int i = 0; i < tasks.size(); i++){
            freq[tasks[i] - 'A']++;
            max_freq = max(freq[tasks[i] - 'A'], max_freq);
        }

        for (int i = 0; i < 26; i++){
            if (max_freq == freq[i]) max_freq_count++;
        }
        return max((int)tasks.size(), (max_freq - 1) * cycle + max_freq_count);
    }
};