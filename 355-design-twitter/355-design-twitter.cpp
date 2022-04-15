class Twitter {
public:
    int time=0;
    unordered_map<int,vector<pair<int,int>> > tweets;
    unordered_map<int,unordered_set<int> > followers;
    unordered_map<int,unordered_set<int>> following;
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
         if(!(following[userId].count(userId))) following[userId].insert(userId);
        tweets[userId].push_back({time,tweetId});
        time++;
    }
    
    vector<int> getNewsFeed(int userId) {
       
     //   vector<int> ans;
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;   
        for(auto& followingPerson: following[userId]){
            for(auto& p: tweets[followingPerson]){
                 pq.push(p);
                if(pq.size()>10) pq.pop();
            }
        }
        vector<int> ans;
        while(pq.size()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
        /*
            1-> {0,5} 
        
            
            following 
            1 -> 2
            2 -> 1
            
            
            follower 
            2-> 1
            1-> 2
        */
        
    }
    
    void follow(int followerId, int followeeId) {
        followers[followeeId].insert(followerId);
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followers[followeeId].erase(followerId);
        following[followerId].erase(followeeId);

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