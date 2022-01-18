class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        int left[n],right=1;
        memset(left,0,sizeof(left));
        int ans=0;
        left[0]=1;
        for(int i=1;i<n;i++){
            if(ratings[i]>ratings[i-1])
                left[i]=1+left[i-1]; //ek candy extra milega..
            else left[i]=1;
        }
        right=1;
        ans=max(left[n-1],right);
        for(int i=n-2;i>=0;i--){
            ans+=max(left[i],(ratings[i]>ratings[i+1]? right=1+right: right=1));
        }
        return ans;
    }
};