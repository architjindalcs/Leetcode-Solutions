class UndergroundSystem {
public:
    unordered_map<string,int> sumTimes;
    unordered_map<string,int> travelsDone;
    unordered_map<int,pair<string,int>> m;
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        m[id]={stationName,t};
    }
    
    void checkOut(int id, string stationName, int t) {
        int entry=m[id].second;
        int exit=t;
        int timeTaken=exit-entry;
        string route=m[id].first+"->"+stationName;
        sumTimes[route]+=timeTaken;
        travelsDone[route]++;
    }
    
    double getAverageTime(string st, string end) {
        string route=st+"->"+end;
        return sumTimes[route]/(1.0*travelsDone[route]);
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */