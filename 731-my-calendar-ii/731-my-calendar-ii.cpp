class MyCalendarTwo {
public:
    map<int,int> m;
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        end--;
        m[start]++;
        m[end+1]--;
        int cs=0;
        for(auto& x: m){
            cs+=(x.second);
            if(cs>=3) {
                m[start]--;
                m[end+1]++;
                return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */