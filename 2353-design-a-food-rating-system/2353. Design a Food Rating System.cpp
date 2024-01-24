class FoodRatings {
public:
    struct cmp{
        bool operator()(const pair<int, string> &a, const pair<int, string> &b) const{
            if (a.first > b.first) return true;
            if (a.first == b.first && a.second < b.second) return true;

            return false;
        }
    };

    vector<string> foods; 
    vector<string> cuisines; 
    vector<int> ratings; 

    unordered_map<string, int> idx;
    unordered_map<string, set<pair<int, string>, cmp>> findHighestRated;

    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        this -> foods = foods; 
        this -> ratings = ratings; 
        this -> cuisines = cuisines; 

        for (int i = 0; i < foods.size(); i++){
            idx[foods[i]] = i;
            findHighestRated[cuisines[i]].insert({ratings[i], foods[i]});
        }
    }
    
    void changeRating(string food, int newRating) {
        findHighestRated[cuisines[idx[food]]].erase({ratings[idx[food]], food});
        findHighestRated[cuisines[idx[food]]].insert({newRating, food});

        ratings[idx[food]] = newRating;
    }
    
    string highestRated(string cuisine) {
        return (*findHighestRated[cuisine].begin()).second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */