class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> v; 

        for (int i = 0; i < operations.size(); i++){
            if (operations[i] == "+"){
                v.push_back(v[v.size() - 1] + v[v.size() - 2]);
            }
            else if (operations[i] == "D"){
                v.push_back(2 * v.back());
            }
            else if (operations[i] == "C"){
                v.pop_back();
            }
            else {
                v.push_back(stoi(operations[i]));
            }
        }

        return accumulate(v.begin(), v.end(), 0);
    }
};