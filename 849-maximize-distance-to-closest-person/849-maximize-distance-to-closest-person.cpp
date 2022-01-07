class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n=seats.size();
        int dist[n];
        memset(dist,-1,sizeof(dist));
        int prevOne=-1;
        for(int i=0;i<n;i++){
            if(seats[i]==1)
                prevOne=i;
            else{
                if(prevOne!=-1)
                dist[i]=i-prevOne;
                else dist[i]=INT_MAX;
            }
        }
     //   for(int i=0;i<n;i++) cout<<dist[i]<<" ";
        prevOne=-1;
        int maxm=0;
        for(int i=n-1;i>=0;i--){
            if(seats[i]==1) prevOne=i;
            else{
                if(prevOne!=-1)
                dist[i]=min(dist[i],prevOne-i);
                maxm=max(maxm,dist[i]);
            }
        }
        return maxm;
    }
};