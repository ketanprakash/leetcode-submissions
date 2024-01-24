class Comparator{
    public:
    bool operator()(string &a, string &b){
        if (a.size() > b.size()) return true;


        if (a.size() == b.size()){
            int i = 0; 
            while (a[i] == b[i] && i < a.size()) i++;

            return i < a.size() && a[i] > b[i];
        }
        
        return false;
    }
};

class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        priority_queue<string, vector<string>, Comparator> q; 

        for (int i = 0; i < nums.size(); i++){
            q.push(nums[i]);
            if (q.size() > k) q.pop();
        }

        return q.top();
    }
};