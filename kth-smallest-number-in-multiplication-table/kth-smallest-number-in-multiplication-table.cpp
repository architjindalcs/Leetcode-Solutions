class Solution {
public:
    int cntLTEK(int r,int c,int mid){
        int ans=0;
        for(int i=1;i<=r;i++){
            ans+=min(c,mid/i);
        }
        return ans;
    }
    int findKthNumber(int r, int c, int k) {
        int st=1,end=r*c;
        while(st<end){
            int mid=(st+(end-st)/2);
            int cnt=cntLTEK(r,c,mid);
            if(cnt>=k) end=mid;
            else st=mid+1;
        }
        return st;
    }
};