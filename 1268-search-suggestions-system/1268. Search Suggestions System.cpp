class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());
        vector<vector<string>> ans;
        string word;
        vector<string> v;
        for (int i = 0; i < searchWord.size(); i++){
            v.clear();
            word.push_back(searchWord[i]);
            int startIdx = lower_bound(products.begin(), products.end(), word) - products.begin();
            word.back()++;
            int endIdx = lower_bound(products.begin(), products.end(), word) - products.begin();
            word.back()--;
            endIdx--;

            for (int j = startIdx; j <= min(endIdx, startIdx + 2); j++){
                v.push_back(products[j]);
            }

            ans.push_back(v);
        }
        
        return ans;
    }
};