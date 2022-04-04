class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(heaters.begin(),heaters.end());
        int maxR=INT_MIN;
        for(int h: houses){
            int st=0,end=heaters.size()-1;
            int idx=-1,minDiff=INT_MAX;
            while(st<=end){
                int mid=(st+end)/2;
                int diff=abs(h-heaters[mid]);
                if(diff==0) {
                    minDiff=0;
                    break;
                }
                minDiff=min(minDiff,diff);
                if(heaters[mid]>h){
                    end=mid-1;
                }
                else st=mid+1;
            }
            maxR=max(maxR,minDiff);
        }
        return maxR;
    }
};