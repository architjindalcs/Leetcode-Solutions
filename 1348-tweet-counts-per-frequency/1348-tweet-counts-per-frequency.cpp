class TweetCounts {
public:
    unordered_map<string,vector<int>> m;
    TweetCounts() {
        
    }
    
    void recordTweet(string tweetName, int time) {
        m[tweetName].push_back(time);
    }
    
    vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime) {
        vector<int> v;
        // st=0,end=60
        //st = 10, 10-69, 
        int interval;
        if(freq=="minute") interval=60;
        else if(freq=="hour") interval=3600;
        else interval=86400;
        int buckets=(endTime-startTime)/(interval);
        
        v=vector<int> (buckets+1,0);
        
        for(int time: m[tweetName]){
            if(time>=startTime and time<=endTime){
                int idx=(time-startTime)/interval;
                v[idx]++;
            }
        }
        return v;
    }
};

/**
 * Your TweetCounts object will be instantiated and called as such:
 * TweetCounts* obj = new TweetCounts();
 * obj->recordTweet(tweetName,time);
 * vector<int> param_2 = obj->getTweetCountsPerFrequency(freq,tweetName,startTime,endTime);
 */