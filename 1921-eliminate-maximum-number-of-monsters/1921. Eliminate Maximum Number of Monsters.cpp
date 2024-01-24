class Solution {
public:
    static bool f(pair<int, int> &a, pair<int, int> &b){
        return (double)a.first / a.second < (double)b.first / b.second;
    }

    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = dist.size();
        vector<pair<int, int>> v; 

        for (int i = 0; i < dist.size(); i++) v.push_back({dist[i], speed[i]});
        sort(v.begin(), v.end(), f);
        for (int i = 0; i < n; i++){
            auto &[d, s] = v[i];
            cout << d << " " << i << " " << s << endl;
            if (d - i * s <= 0) return i;
        }
        return n;
    }
};