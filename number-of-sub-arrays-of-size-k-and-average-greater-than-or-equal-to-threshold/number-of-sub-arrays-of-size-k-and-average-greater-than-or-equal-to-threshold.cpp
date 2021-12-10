class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int cnt=0,n=arr.size();
        int pre[n];
        pre[0]=arr[0];
        int ans=0;
        for(int i=1;i<n;i++) pre[i]=arr[i]+pre[i-1];
        for(int i=0;i<=(n-k);i++)
        {
            int st=i,end=i+k-1;
            int sum=pre[end]-(st? pre[st-1]: 0);
            if(sum/(1.0*k)>=threshold) ans++;
        }
        return ans;
    }
};