class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int maxm=0;
        int n=seats.size();
        int last=-1;
        for(int i=0;i<seats.size();i++){
            if(seats[i]==1){
                maxm=last<0? i: max(maxm,(i-last)/2);
                last=i;
            }
        }
        maxm=max(maxm,n-1-last);
        return maxm;
    }
};