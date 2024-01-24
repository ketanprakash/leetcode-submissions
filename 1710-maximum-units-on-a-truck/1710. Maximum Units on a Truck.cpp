class Solution {
public:
    static bool f(vector<int> &a, vector<int> &b){
        return a[1] > b[1];
    }

    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int val = 0;
        sort(boxTypes.begin(), boxTypes.end(), f);

        for (int i = 0; i < boxTypes.size(); i++){
            val += boxTypes[i][1] * min(truckSize, boxTypes[i][0]);
            truckSize -= min(truckSize, boxTypes[i][0]);
        }

        return val;
    }
};