class Solution {
public:
    bool poss(vector<int>& time,long long ttime,int totalTrips){
        long long cnt=0;
        for(int t: time){
            if(cnt>=totalTrips) return true;
            cnt+=(ttime/(long long)t);
        }
        
        return cnt>=totalTrips;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long st=0,end=LLONG_MAX;
        
        long long two=(long long)2;
        long long ans;
        while(st<=end){
            long long mid=(st+(end-st)/two);
      //      cout<<"mid: "<<mid<<endl;
            if(poss(time,mid,totalTrips)){
        //        cout<<"ans: "<<mid<<endl;
                ans=mid;
                end=mid-1;
            }
            else st=mid+1;
        }
        return ans;
    }
};