class Solution {
public:
    bool poss(vector<int>& piles,int speed,int hrs){
        int time=0;
        for(int i=0;i<piles.size();i++){
            time+=(piles[i]%speed==0? piles[i]/speed : ((piles[i]/speed)+1));
        }
        return time<=hrs;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int st=1,end=0;
        for(int i: piles) end=max(end,i);
        int ans=-1;
        while(st<=end){
            int mid=(st+end)/2;
            if(poss(piles,mid,h)){
                ans=mid;
                end=mid-1;
            }
            else  st=mid+1;
        }
        return ans;
    }
};