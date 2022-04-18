class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int ans=0,maxm=INT_MIN;
        for(int i=0;i<arr.size();i++){
            maxm=max(maxm,arr[i]);
            if(maxm==i) ans++;
        }
        return ans;
    }
};