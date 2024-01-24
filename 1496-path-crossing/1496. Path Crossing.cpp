struct hashFunction 
{ 
  size_t operator()(const pair<int ,  
                    int> &x) const
  { 
    return x.first ^ x.second; 
  } 
};

class Solution {
public:
    bool isPathCrossing(string path) {
        unordered_set<pair<int, int>, hashFunction> s;
        s.insert({0, 0});
        int x = 0, y = 0;
        for (char &ch : path){
            if (ch == 'N') y++;
            if (ch == 'S') y--;
            if (ch == 'E') x++;
            if (ch == 'W') x--;
            if (s.count({x, y})) return true;
            s.insert({x, y});
        }
        
        return false;
    }
};