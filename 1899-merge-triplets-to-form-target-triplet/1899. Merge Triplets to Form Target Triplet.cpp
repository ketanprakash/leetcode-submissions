class Solution {
public:
    bool check(vector<int> &triplet, vector<int> &target, int idx){
        for (int i = 0; i < 3; i++){
            if (idx == i && target[i] != triplet[i]) return false;
            else if (target[i] < triplet[i]) return false;
        }

        return true;
    }

    void helper(vector<int> &triplet1, vector<int> &triplet2){
        if (triplet1.size() == 3 && triplet2.size() == 3){
            triplet1 = {max(triplet1[0], triplet2[0]), max(triplet1[1], triplet2[1]), max(triplet1[2], triplet2[2])};
            triplet2 = triplet1;
        }
    }

    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<int> triplet1, triplet2, triplet3;
        vector<int> triplet{-1, -1, -1};
        for (int i = 0; i < triplets.size(); i++){
            if (check(triplets[i], target, 0)) triplet1 = triplets[i];
            if (check(triplets[i], target, 1)) triplet2 = triplets[i];
            if (check(triplets[i], target, 2)) triplet3 = triplets[i];
        }
        helper(triplet1, triplet);
        helper(triplet2, triplet);
        helper(triplet3, triplet);

        return triplet == target;
    }
};