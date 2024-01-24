class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> m;

    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        m[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        int s = 0, e = m[key].size() - 1, mid;
        string ans = "";

        while (s <= e){
            mid = s + (e - s) / 2; 

            if (m[key][mid].first <= timestamp){
                ans = m[key][mid].second; 
                s = mid + 1;
            }
            else e = mid - 1;
        }

        return ans;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */