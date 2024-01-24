class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> v; 
        int n = potions.size(), count;
        sort(potions.begin(), potions.end());
        for (int i = 0; i < spells.size(); i++){
            count = n - (lower_bound(potions.begin(), potions.end(), ceil((double)success / spells[i])) - potions.begin());
            v.push_back(count);
        }
        return v;
    }
};