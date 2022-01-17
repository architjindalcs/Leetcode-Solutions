class Solution {
public:
    int maxAbsValExpr(vector<int>& arr1, vector<int>& arr2){
        vector<int> maxm(4,INT_MIN);
        vector<int> minm(4,INT_MAX);
        for(int i=0;i<arr1.size();i++){
            maxm[0]=max(maxm[0],arr1[i]+arr2[i]+i);
            minm[0]=min(minm[0],arr1[i]+arr2[i]+i);
            
            maxm[1]=max(maxm[1],arr1[i]+arr2[i]-i);
            minm[1]=min(minm[1],arr1[i]+arr2[i]-i);
            
            maxm[2]=max(maxm[2],arr1[i]-arr2[i]+i);
            minm[2]=min(minm[2],arr1[i]-arr2[i]+i);
        
            maxm[3]=max(maxm[3],arr1[i]-arr2[i]-i);
            minm[3]=min(minm[3],arr1[i]-arr2[i]-i);
        }
        int ans=INT_MIN;
        for(int i=0;i<4;i++) ans=max(ans,maxm[i]-minm[i]);
        return ans;
    }
};