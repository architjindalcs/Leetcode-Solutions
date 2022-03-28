class Solution {
public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int swap[n],noswap[n];
        memset(swap,0,sizeof(swap));
        memset(noswap,0,sizeof(noswap));
        swap[0]=1; noswap[0]=0;
        
        for(int i=1;i<n;i++){
            swap[i]=noswap[i]=INT_MAX;
            /*
               2   5
               3   6
            */
            
            if(nums1[i]>nums1[i-1] and nums2[i]>nums2[i-1]){
                swap[i]=min(swap[i],1+swap[i-1]);
                noswap[i]=noswap[i-1];
            }
            
            if(nums1[i]>nums2[i-1] and nums2[i]>nums1[i-1]){
                swap[i]=min(swap[i],1+noswap[i-1]);
                noswap[i]=min(noswap[i],swap[i-1]);
            }
        }
        return min(swap[n-1],noswap[n-1]);
        
        
    }
};