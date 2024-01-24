struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const
    {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
 
        if (hash1 != hash2) {
            return hash1 ^ hash2;              
        }
         
        // If hash1 == hash2, their XOR is zero.
        return hash1;
    }
};

class UndergroundSystem {
public:
    unordered_map<pair<string, string>, pair<double, int>, hash_pair> avg;
    unordered_map<int, pair<string, int>> enter;

    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        enter[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        string enterStationName = enter[id].first;
        int enterTime = enter[id].second;
        int duration = t - enterTime;
        enter.erase(id);

        if (avg.count({enterStationName, stationName})){
            double prevAvg = avg[{enterStationName, stationName}].first;
            int prevNumber = avg[{enterStationName, stationName}].second;


            double newAvg = ((double)prevAvg * prevNumber + duration) / (prevNumber + 1);
            int newNumber = prevNumber + 1;
            avg[{enterStationName, stationName}] = {newAvg, newNumber};
        }
        else {
            avg[{enterStationName, stationName}] = {duration, 1};
        }
    }
    
    double getAverageTime(string startStation, string endStation) {
        return avg[{startStation, endStation}].first;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */