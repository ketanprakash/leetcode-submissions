class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int sum = 0, mid = 0, index = 0;
        for (int i = 0; i < n; i++){
            sum += gas[i] - cost[i];
            mid += gas[i] - cost[i];

            if (mid < 0){
                index = i + 1; 
                mid = 0;
            }
        }

        return sum < 0 ? -1 : index;
    }
};