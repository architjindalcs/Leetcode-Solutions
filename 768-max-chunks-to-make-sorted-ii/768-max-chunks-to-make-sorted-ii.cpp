class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int ans=0; int n=arr.size();
        vector<int> rightMin(n);
        rightMin[n-1]=arr[n-1];
        for(int i=n-2;i>=0;i--) rightMin[i]=min(arr[i],rightMin[i+1]);
        int lmax=INT_MIN;
        for(int i=0;i<n-1;i++){
            lmax=max(lmax,arr[i]);
            if(lmax<=rightMin[i+1]) ans+=1;
        }
        return ++ans;
    }
};