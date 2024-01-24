bool f(pair<int, double> &p1, pair<int, double> &p2){
    return p1.first > p2.first;
}

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        if (position.size() == 0) return 0;

        vector<pair<int, double>> pairs; 

        for (int i = 0; i < position.size(); i++){
            pairs.push_back({position[i], (target - position[i]) / (double)speed[i]});
        }

        sort(pairs.begin(), pairs.end(), f);

        int fleets = 1; 
        double time = pairs[0].second;

        for (int i = 1; i < pairs.size(); i++){
            if (pairs[i].second > time){
                fleets++;
                time = pairs[i].second;
            }
        }

        return fleets;
    }
};