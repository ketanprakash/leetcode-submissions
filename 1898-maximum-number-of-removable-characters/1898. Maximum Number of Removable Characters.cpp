class Solution {
public:
    bool check(string &str, string &p, unordered_map<int, int> &m, int k){
        int j = 0;

        for (int i = 0; i < str.size(); i++){
            if (m.count(i) && m[i] < k) continue;

            if (str[i] == p[j]) j++;
        }

        return j == p.size();
    }

    int maximumRemovals(string str, string p, vector<int>& removable) {
        unordered_map<int, int> m; 

        for (int i = 0; i < removable.size(); i++){
            m[removable[i]] = i;
        } 

        int l = 0, r = removable.size(), mid, ans = 0; 

        while (l <= r){
            mid = l + (r - l) / 2;

            if (check(str, p, m, mid)){
                ans = mid;
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }

        return ans;
    }
};