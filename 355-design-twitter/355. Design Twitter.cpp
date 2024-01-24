class Twitter {
public:
    Twitter() {
        
    }
    int timer = 0;
    unordered_map<int, unordered_set<int>> follows;
    unordered_map<int, vector<pair<int,int>>> posts;
    
    void postTweet(int userId, int tweetId) {
        posts[userId].push_back({timer++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q; 

        for (auto i : posts[userId]){
            q.push(i);
            if (q.size() > 10) q.pop();
        }

        for (int i : follows[userId]){
            for (auto j : posts[i]){
                q.push(j);
                if (q.size() > 10) q.pop();
            }
        }

        vector<int> ans; 
        while (!q.empty()){
            ans.push_back(q.top().second);
            q.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        follows[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        follows[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */