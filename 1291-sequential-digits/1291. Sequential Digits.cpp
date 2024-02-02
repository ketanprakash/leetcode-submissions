class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string str = "123456789";
        string start = to_string(low);
        string end = to_string(high);

        int size = start.size(); 
        int num;
        vector<int> ans;
        while (size <= end.size()){
            for (int i = 0; i <= 8 - size + 1; i++){
                num = stoi(str.substr(i, size));
                if (num >= low && num <= high) ans.push_back(num);
            }
            size++;
        }

        return ans;
    }
};