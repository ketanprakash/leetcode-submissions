class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        unordered_map<int, int> m;

        int s = 0, e = 0; 
        m[fruits[0]] = 0;
        int ans = 1;

        while (e + 1 < n){
            if (fruits[e + 1] != fruits[e]){
                m[fruits[e + 1]] = e + 1;
            }

            if (m.size() == 3){
                s = m[fruits[e]];
                m.clear();
                m[fruits[e + 1]] = e + 1; 
                m[fruits[s]] = s;
            }
            e++;

            ans = max(ans, e - s + 1);
        }

        return ans;
    }
};